#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include <map>
#include <string>
#include <IceUtil/Mutex.h>
#include <OWS.h>
#include "DataNode.h"

/*
 * @brief 数据提供类，纯虚类
 */
class DataProvider
{
public:
	virtual ~DataProvider(){};
    /*
     * @brief 线程池模板调用该函数来执行具体的任务，由具体子类实现
     */
	virtual void process() = 0;

    /*
     * @brief 获取数据节点
     * @return 数据节点
     */
    virtual DataNode* GetDataNode() = 0;
};

#endif
