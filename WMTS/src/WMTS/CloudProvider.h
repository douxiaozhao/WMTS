#pragma once

#include "../Data/DataProvider.h"
#include "../Data/SingleBufNode.h"
#include <string>

/*
 * @brief 云端瓦片提供类，通过http服务获取瓦片
 */
class CloudProvider : public DataProvider
{
public:
	CloudProvider(const char*, int , int, int, SingleBufNode* );
	~CloudProvider(void);
	/*
	 * @brief 线程池模板调用函数
	 */
	virtual void process();

	/*
	 * @brief: 获取数据节点
	 * @return: 返回数据块节点
	 */
	virtual DataNode* GetDataNode();

private:
	/*
	 * @brief: 获取瓦片
	 */
	virtual void getTile();
	/*
	 * @brief: C++调用网络服务回调接口
	 * @return: 返回数据块长度
	 */
	static size_t WriteMemoryCallback(void *, size_t, size_t, void *);

private:
	const std::string layer;            //图层
	int level, x, y;					//等级，x，y
	SingleBufNode *node;                //数据块节点 
};

