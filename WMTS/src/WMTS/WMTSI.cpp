#include "WMTSI.h"
#include <Ice/Ice.h>
#include <IceUtil/UUID.h>
#include <iostream>
#include <fstream>
#include <string>
#include "LocalProvider.h"
#include "../Data/DataNode.h"
#include "../Data/SingleBufNode.h"
#include "CapabilitiesProvider.h"
#include "EngineTileProvider.h"


WMTSI::WMTSI(const std::string& name, const std::string& cfgFile) 
	: _name(name), data_process(DataProcess::getInstance())
{
	initServer(cfgFile);           // 初始化TileEngine的数据源信息

	std::cout << "WMTS servant 初始化成功" << std::endl;
}


WMTSI::~WMTSI(void)
{
	std::cout << "销毁WMTS servant实例" << std::endl;

	for(std::map<std::string, PyramidStore*>::iterator it = store_list.begin(); it != store_list.end(); ++it)
		if(it->second != NULL)
		{
			std::cout << "destroy source: " << it->first << std::endl;
			it->second->disConnect();
			StoreFactory::releaseStore(it->second);
		}
	store_list.clear();

	DataProcess::destroyInstance();
}

OWSMODULE::OWSTask
WMTSI::GetCapabilities(const ::Ice::Current& c)
{
	OWSMODULE::OWSTask task;
	task.taskID = IceUtil::generateUUID();
	task.state = OWSMODULE::OWSWAIT;

    SingleBufNode *node = new SingleBufNode();
    node->SetTaskID(task.taskID);
    node->SetTaskState(task.state);

	//std::cout << "GetCapabilities" << std::endl;

	if(store_list.empty())
	{
		std::cout << "初始化数据源失败" << std::endl;
		delete node;
		task.state = OWSMODULE::OWSERROR;
		return task;
	}

	DataProvider *provider = new CapabilitiesProvider(node, &store_list);

	if(data_process->CreateDataTask(provider) == false)
	{
		std::cout << "error" << std::endl;
		delete node;
		delete provider;
		task.state = OWSMODULE::OWSERROR;
	}
	return task;
}

OWSMODULE::OWSTask 
	WMTSI::GetTile(const WMTSMODULE::GetTileParameter& parameter, const ::Ice::Current& c)
{
#ifdef OGCDEBUG
	std::cout << "GetTile" << std::endl;
#endif
	OWSMODULE::OWSTask task;
	task.taskID = IceUtil::generateUUID();

	task.state = OWSMODULE::OWSWAIT;

	//创建一个数据节点
	SingleBufNode* node = new SingleBufNode();
	node->SetTaskID(task.taskID);
	node->SetTaskState(task.state);

	//DataProvider *provider = new LocalProvider(parameter.layer, parameter.style, parameter.format, 
		//parameter.level, parameter.row, parameter.col, node);

	//std::cout << parameter.layer << " " << parameter.level << " " << parameter.col << " " << parameter.row << std::endl;

	/*FILE *flog = fopen("F:OGC.log", "a+");
	fprintf(flog, "%s %-4d %-4d %-4d\n", parameter.layer.c_str(), parameter.level, parameter.col, parameter.row);
	fclose(flog);*/

	std::string layer, source;
	int pos = parameter.layer.find_last_of('_', parameter.layer.length()-1);
	if(pos == -1)
	{
		delete node;
		task.state = OWSMODULE::OWSERROR;
		return task;
	}

	layer = parameter.layer.substr(0, pos);
	source = parameter.layer.substr(pos+1, parameter.layer.length()-1-pos);

	std::map<std::string, PyramidStore*>::iterator it = store_list.find(source);      //获取该数据源对应的金字塔仓库 
	if(it == store_list.end())
	{
		delete node;
		task.state = OWSMODULE::OWSERROR;
		return task;
	}

	PyramidStore *store = it->second;

	DataProvider *provider = new EngineTileProvider(layer, parameter.format, parameter.level, parameter.col, parameter.row, node, store);

	if(data_process->CreateDataTask(provider) == false)
	{
		delete node;
		delete provider;
		task.state = OWSMODULE::OWSERROR;
	}

	return task;
}

OWSMODULE::OWSTask
	WMTSI::GetFeatureInfo(const WMTSMODULE::GetTileParameter& parameter, ::Ice::Int I, ::Ice::Int J, const std::string& informat, const ::Ice::Current& c)
{
	OWSMODULE::OWSTask task;
	task.taskID = "NULL";
	task.state = OWSMODULE::OWSERROR;
	return task;
}

void
	WMTSI::CheckState(const std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Current& c)
{
#ifdef OGCDEBUG
	std::cout << "Check" << std::endl;
#endif
	//Sleep(1000);
	task = data_process->GetTaskState(taskID);
}

::Ice::Int
	WMTSI::ReadData(const std::string& taskID, ::OWSMODULE::byteSeq& dataBlock, const ::Ice::Current& c)
{
#ifdef OGCDEBUG
		std::cout << "read " << std::endl;
#endif
	return data_process->GetData(taskID, dataBlock);
}

void
	WMTSI::shutdown(const ::Ice::Current& c)
{
	std::cout << "shut down the service" << std::endl;
	c.adapter->getCommunicator()->shutdown();        
}

void WMTSI::initServer( const std::string& cfg)
{
	std::ifstream fin(cfg.c_str());
	if(!fin.is_open())
		return;
	char tempLine[100];
	fin.getline(tempLine, 100);

	int flag, num;
	char **arv = new char *[5];
	char temp[6][30];
	std::string source_name;

	for(int i = 0; i < 4; ++i)
	{
		fin >> source_name;
		fin >> flag;
		if (flag == 0)
		{
			fin.getline(tempLine, 100);
			continue;
		}
		fin >> num;
		for(int j = 0; j < num; j++)
		{
			fin >> temp[j];
			arv[j] = temp[j];
		}
		PyramidStore *store = NULL;
		if(source_name == "cloud")
			store = StoreFactory::createStore(STORE_IN_CLOUD, num, arv);
		else if(source_name == "localFS")
			store = StoreFactory::createStore(STORE_IN_LOCALFS, num, arv);
		else if(source_name == "localDB")
			store = StoreFactory::createStore(STORE_IN_LOCALDB, num, arv);
		else if(source_name == "multiDB")
			store = StoreFactory::createStore(STORE_IN_MULTIDB, num, arv);

		if(store != NULL)
		{
			store->connect();
			store_list.insert(make_pair(source_name, store));
		}
	}

	fin.close();
}
