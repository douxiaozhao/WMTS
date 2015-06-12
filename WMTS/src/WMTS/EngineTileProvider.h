#ifndef ENGINE_TILE_PROVIDER_H
#define ENGINE_TILE_PROVIDER_H

//本地瓦片提供者

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include "WMTSI.h"
#include <string>

/*
 * @brief TileEngine瓦片提供类
 */
class EngineTileProvider : public DataProvider
{
public:
    /*
     * @brief 构造函数
     * @parm  数据块节点
     */
	EngineTileProvider(const std::string &, const std::string &, int, int, int, SingleBufNode*, PyramidStore*);

	virtual ~EngineTileProvider();

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
    const std::string layer, format;
    int level, x, y;
	SingleBufNode *node;                     //数据块节点 
	PyramidStore *store;
	static const int BUFSIZE  = 1024 * 10;
};

#endif
