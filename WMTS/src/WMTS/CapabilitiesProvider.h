#ifndef CAPABILITIES_PROVIDER_H
#define CAPABILITIES_PROVIDER_H

//本地瓦片提供者

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include "WMTSI.h"
#include <string>
#include <tinyxml.h>

/*
 * @brief 本地文件系统瓦片提供类
 */
class CapabilitiesProvider : public DataProvider
{
public:
    /*
     * @brief 构造函数
     * @parm  数据块节点
     */
	CapabilitiesProvider(SingleBufNode*, std::map<std::string, PyramidStore*> *);

	virtual ~CapabilitiesProvider();

    /*
     * @brief 线程池模板调用该函数来执行具体的任务
     */
	virtual void process(); 
    /*
     * @brief 获取数据节点
     * @return 数据节点
     */
	virtual DataNode* GetDataNode();

private:
    /*
     * @brief 获取瓦片
     */
	virtual void getCapabilities();
	char* getContents(int &);
	void releaseContests(char*);
	bool insertSingleTileMatrixSet(TiXmlElement *contents, TiXmlElement *e, const std::string &);
	bool insertSingleLayer(TiXmlElement *contents, TiXmlElement *e, const std::string &);

private:
	SingleBufNode *node;							    // 数据块节点 
	std::map<std::string, PyramidStore*>* store_list;   // 保存各种数据源的金字塔仓库, 分别保存金字塔仓库和对应的类型
	static const int BUFSIZE  = 1024 * 10;
};

#endif