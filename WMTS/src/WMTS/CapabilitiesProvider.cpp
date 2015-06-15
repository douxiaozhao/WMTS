#include "CapabilitiesProvider.h"

CapabilitiesProvider::CapabilitiesProvider( SingleBufNode* node, std::map<std::string, PyramidStore*>* store_list) : node(node), store_list(store_list)
{
}

void CapabilitiesProvider::process()
{
	std::cout << "capabilities process" << std::endl;
	getCapabilities();
}

void CapabilitiesProvider::getCapabilities()
{
	int len = 0;

	char *contests = getContents(len);
	node->AllocateMem(len);
	memcpy(node->GetBuf(), contests, len);
	releaseContests(contests);

	node->SetLen(len);
	node->SetTaskState(OWSMODULE::OWSSTART);
}

DataNode* CapabilitiesProvider::GetDataNode()
{
	return node;
}

char* CapabilitiesProvider::getContents(int &len)
{
	len = 0;

	TiXmlDocument *ogcDoc = new TiXmlDocument();
	if(NULL == ogcDoc)
		return NULL;
	ogcDoc->LoadFile("contentsTemplate.xml");
	TiXmlElement *contents = ogcDoc->RootElement()->FirstChildElement();

	std::map<TiXmlDocument*, std::string> originalDocInfo;	//原始金字塔目录集合以及对应的源

	//将各种源的元数据xml信息收集起来
	for(std::map<std::string, PyramidStore*>::iterator it = store_list->begin(); it != store_list->end(); ++it)
		if(it->second != NULL)
		{
			int l = 0;
			char *buf = it->second->getAllPyramidsDescription(l);

			std::cout << it->first << std::endl;
			std::cout << buf << std::endl << std::endl;

			TiXmlDocument *doc = new TiXmlDocument();
			doc->Parse(buf);
			it->second->releaseAllPyramidsDescription(buf);
			originalDocInfo.insert(make_pair(doc, it->first));
		}

	//转换格式
	//将所有layer插入
	for(std::map<TiXmlDocument*, std::string>::iterator it = originalDocInfo.begin(); it != originalDocInfo.end(); ++it)
	{
		TiXmlElement *originalRoot = it->first->RootElement();
		for(TiXmlElement *e = originalRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
			insertSingleLayer(contents, e, it->second);
	}
	//将所有TileMatrix插入
	for(std::map<TiXmlDocument*, std::string>::iterator it = originalDocInfo.begin(); it != originalDocInfo.end(); ++it)
	{
		TiXmlElement *originalRoot = it->first->RootElement();
		for(TiXmlElement *e = originalRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
			insertSingleTileMatrixSet(contents, e, it->second);

		delete(it->first);
	}

#ifdef WMTS_DEBUG
	ogcDoc->Print();
#endif

	TiXmlPrinter printer;
	ogcDoc->Accept(&printer);

	len = printer.Size();
	printer.SetLineBreak("\0");

	char *buf = new char[len];
	memset(buf, 0, sizeof(buf));
	memcpy(buf, printer.CStr(), len);

	delete ogcDoc;

#ifdef WMTS_DEBUG
	std::cout << __FILE__ << __LINE__ << std::endl;
	std::cout <<"len: " << len << "  " << buf << std::endl;
#endif
	return buf;
}

bool CapabilitiesProvider::insertSingleLayer(TiXmlElement *contents, TiXmlElement *e, const std::string & source)
{
	string temp, name;
	TiXmlElement layer("Layer");

	name.clear();
	name.append(e->Attribute("name")).append("_").append(source);

	//Title
	TiXmlElement title("ows:Title");
	title.InsertEndChild(TiXmlText(name.c_str()));
	layer.InsertEndChild(title);

	//Abstract
	TiXmlElement dataAbstract("ows:Abstract");
	dataAbstract.InsertEndChild(TiXmlText(e->Attribute("dataType")));
	layer.InsertEndChild(dataAbstract);

	//Identifier
	TiXmlElement identifier("ows:Identifier");
	identifier.InsertEndChild(TiXmlText(name.c_str()));
	layer.InsertEndChild(identifier);

	//BoundingBox
	TiXmlElement box("ows:BoundingBox");
	TiXmlElement lowerCorner("ows:LowerCorner");
	temp.append(e->Attribute("west")).append(" ").append(e->Attribute("south"));
	lowerCorner.InsertEndChild(TiXmlText(temp.c_str()));
	box.InsertEndChild(lowerCorner);
	TiXmlElement upperCorner("ows:UpperCorner");
	temp.clear();
	temp.append(e->Attribute("east")).append(" ").append(e->Attribute("north"));
	upperCorner.InsertEndChild(TiXmlText(temp.c_str()));
	box.InsertEndChild(upperCorner);
	layer.InsertEndChild(box);

	//Style
	TiXmlElement style("Style");
	TiXmlElement identifier2("ows:Identifier");
	identifier2.InsertEndChild(TiXmlText("default"));
	style.InsertEndChild(identifier2);
	layer.InsertEndChild(style);

	//Format
	TiXmlElement format("Format");
	format.InsertEndChild(TiXmlText(e->Attribute("tileFormat")));
	layer.InsertEndChild(format);

	//TileMatrixSetLink
	TiXmlElement tileMatrixSetLink("TileMatrixSetLink");
	TiXmlElement tileMatrixSet("TileMatrixSet");
	tileMatrixSet.InsertEndChild(TiXmlText(name.c_str()));
	tileMatrixSetLink.InsertEndChild(tileMatrixSet);
	layer.InsertEndChild(tileMatrixSetLink);

	contents->InsertEndChild(layer);
	return true;
}

bool CapabilitiesProvider::insertSingleTileMatrixSet(TiXmlElement *contents, TiXmlElement *e, const std::string & source)
{
	string temp, name;
	char intTemp[32];
	TiXmlElement tileMatrixSet("TileMatrixSet");

	name.clear();
	name.append(e->Attribute("name")).append("_").append(source);

	//std::cout << "name: " << name << std::endl;

	//Identifier
	TiXmlElement identifier("ows:Identifier");
	identifier.InsertEndChild(TiXmlText(name.c_str()));
	tileMatrixSet.InsertEndChild(identifier);

	//SupportedCRS
	TiXmlElement supportedCRS("ows:SupportedCRS");
	temp.clear();
	if(strcmp(e->Attribute("schemaType"), "SCHEMA_GEODETIC") == 0)
		temp.append("EPSG:4326");    //经纬度
	else
		temp.append("EPSG:3857");    //墨卡托
	supportedCRS.InsertEndChild(TiXmlText(temp.c_str()));
	tileMatrixSet.InsertEndChild(supportedCRS);

	int minLevel, maxLevel;
	if(e->QueryIntAttribute("minLevel", &minLevel) != TIXML_SUCCESS)
		minLevel = 0;
	if(e->QueryIntAttribute("maxLevel", &maxLevel) != TIXML_SUCCESS)
		maxLevel = -1;

	//std::cout << minLevel << "  " << maxLevel << std::endl;

	for(int i = minLevel; i <= maxLevel; ++i)
	{
		//std::cout << "cur level: " << i << std::endl;
		memset(intTemp, 0, sizeof(intTemp));
		sprintf_s(intTemp, "%d", i);
		TiXmlElement tileMatrix("TileMatrix");

		//Identifier
		TiXmlElement identifier("ows:Identifier");
		identifier.InsertEndChild(TiXmlText(intTemp));
		tileMatrix.InsertEndChild(identifier);

		//ScaleDenomiator
		TiXmlElement scaleDenomiator("ScaleDenomiator");
		scaleDenomiator.InsertEndChild(TiXmlText("???"));
		tileMatrix.InsertEndChild(scaleDenomiator);

		//TopLeftCorner
		TiXmlElement topLeftCorner("TopLeftCorner");
		temp.clear();
		temp.append(e->Attribute("north")).append(" ").append(e->Attribute("west"));
		topLeftCorner.InsertEndChild(TiXmlText(temp.c_str()));
		tileMatrix.InsertEndChild(topLeftCorner);

		//TileWidth
		TiXmlElement tileWidth("TileWidth");
		tileWidth.InsertEndChild(TiXmlText(e->Attribute("tileSize")));
		tileMatrix.InsertEndChild(tileWidth);

		//TileHeight
		TiXmlElement tileHeight("TileHeight");
		tileHeight.InsertEndChild(TiXmlText(e->Attribute("tileSize")));
		tileMatrix.InsertEndChild(tileHeight);

		int x, y;
		x = y = 1 << i;
		if(strcmp(e->Attribute("schemaType"), "SCHEMA_MERCATOR") != 0)
			x *= 2;

		//MatrixWidth
		TiXmlElement matrixWidth("MatrixWidth");
		memset(intTemp, 0, sizeof(intTemp));
		sprintf_s(intTemp, "%d", x);
		matrixWidth.InsertEndChild(TiXmlText(intTemp));
		tileMatrix.InsertEndChild(matrixWidth);

		//MatrixHeight
		TiXmlElement matrixHeight("MatrixHeight");
		memset(intTemp, 0, sizeof(intTemp));
		sprintf_s(intTemp, "%d", y);
		matrixHeight.InsertEndChild(TiXmlText(intTemp));
		tileMatrix.InsertEndChild(matrixHeight);

		tileMatrixSet.InsertEndChild(tileMatrix);
	}
	contents->InsertEndChild(tileMatrixSet);
	return true;
}

CapabilitiesProvider::~CapabilitiesProvider()
{
	//std::cout << "CapabilitiesProvider destroy!" << std::endl;
}

void CapabilitiesProvider::releaseContests( char* buf)
{
	delete[] buf;
}
