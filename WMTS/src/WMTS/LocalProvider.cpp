#include "LocalProvider.h"
#include <stdio.h>

LocalProvider::LocalProvider(const std::string& layer, const std::string& style, const std::string& format, int level, int row, int col, SingleBufNode* node) : 
	layer(layer), style(style), format(format), level(level), row(row), col(col), node(node), dir("E:/mapData/map")
{
}

void LocalProvider::process()
{
	getTile();
}

void LocalProvider::getTile()
{
	char fname[100];
	memset(fname, 0, sizeof(fname));
	sprintf_s(fname, "%s/%s/%d/%d/%d#%d#%d.PNG", dir.c_str(), layer.c_str(), level, row, level, row, col);

	int len = 0;

	FILE *fin = NULL;
	errno_t err = fopen_s(&fin, fname, "rb");
	if(err != 0)
	{
#ifdef DEBUG
		std::cout << layer << "#" << level << "#" << row << "#" << col << " 没有该文件" << std::endl;
#endif
		node->SetTaskState(OWSMODULE::OWSERROR);
		return;
	}

	while(true){
		node->AllocateMem(BUFSIZE);
		int num = fread(node->GetBuf()+len, 1, BUFSIZE, fin);
		len += num;
		if(feof(fin))
		{
#ifdef DEBUG
			std::cout << layer << "#" << level << "#" << row << "#" << col << " 读取完毕" << std::endl;
#endif
			std::cout << layer << "#" << level << "#" << row << "#" << col << " 读取完毕" << std::endl;
			fclose(fin);
			break;
		}
	}
	
	node->SetLen(len);
	node->SetTaskState(OWSMODULE::OWSSTART);
}

DataNode* LocalProvider::GetDataNode()
{
	return node;
}
