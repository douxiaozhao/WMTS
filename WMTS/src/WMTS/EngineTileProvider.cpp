#include "EngineTileProvider.h"
#include <time.h>

EngineTileProvider::EngineTileProvider(const std::string &layer, const std::string &format, int level, int x, int y, SingleBufNode* node, PyramidStore* store) : layer(layer), format(format), level(level), x(x), y(y), node(node), store(store)
{
}


void EngineTileProvider::process()
{
	getTile();
}

void EngineTileProvider::getTile()
{
    long len = 0;
    char *buf = NULL;
    bool flag = store->pyramidExist((char*)layer.c_str());	
    Pyramid *db = NULL;
    StructMetaData *smd = NULL;
    if(flag)
    {
		//smd = store->getPyramidMetaData( (char*)layer.c_str() );
		//db = store->getPyramidByPmd(smd);
		db = store->getPyramidByName((char*)layer.c_str());
        if(db != NULL)
        {
			//clock_t begin, end;
			//begin = clock();
	
            buf = db->getTileData(level, y, x, (char*)format.c_str(), len);
			//end = clock();
			//std::cout << "get one tile time: " << end - begin << std::endl;
            if(buf != NULL && len > 0)
            {
                node->AllocateMem(len);
                memcpy(node->GetBuf(), buf, len);
                db->releaseTileData(buf);
				//FILE *flog = fopen("F:OGC.log", "a+");
				//fprintf(flog, "%s %d %d %d 加载成功\n", layer.c_str(), level, y, x);
				//fclose(flog);
            }
			else 
			{
				len = 0;
				//FILE *flog = fopen("F:OGC.log", "w+");
				//fprintf(flog, "%s %d %d %d 没图片\n", layer.c_str(), level, y, x);
				//fclose(flog);
			}
			//store->releasePyramidMetaData(smd);
            store->releasePyramid(db);
        }
    }

	node->SetLen(len);
	if(len > 0)
		node->SetTaskState(OWSMODULE::OWSSTART);
	else
		node->SetTaskState(OWSMODULE::OWSERROR);
}

DataNode* EngineTileProvider::GetDataNode()
{
	return node;
}

EngineTileProvider::~EngineTileProvider()
{
}
