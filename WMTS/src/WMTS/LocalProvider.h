#ifndef LOCAL_TILE_PROVIDER_H
#define LOCAL_TILE_PROVIDER_H

//本地瓦片提供者

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include <WMTS.h>
#include <string>

/*
 * @brief 本地文件系统瓦片提供类
 */
class LocalProvider : public DataProvider
{
public:
    /*
     * @brief 构造函数
     * @parm 图层、风格、格式、等级、x、y、数据块节点
     */
	LocalProvider(const std::string&, const std::string&, const std::string&, int, int, int, SingleBufNode*);

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
	virtual void getTile();

private:
	const std::string layer, style, format;  //图层、样式、格式
	int level, row, col;                     //等级 x y
	const std::string dir;                   //瓦片图层所在目录

	SingleBufNode *node;                     //数据块节点 

	static const int BUFSIZE	     = 1024 * 10;
};

#endif
