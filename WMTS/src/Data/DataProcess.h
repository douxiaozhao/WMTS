#ifndef DATA_OPERATION_H
#define DATA_OPERATION_H

#include "threadpool.h"
#include "DataNode.h"
#include "DataProvider.h"
#include <map>
#include <string>
#include <IceUtil/Mutex.h>
#include <OWS.h>

/*
 * @brief 数据处理来，是一个单例
 */
class DataProcess
{
public:
	static DataProcess* uniqueInstance;            //单例指针
	static DataProcess* getInstance();             //返回单例
	static void destroyInstance();                 //销毁实例

    /*
     * @brief 创建一个数据任务
     * @parm provider 数据提供类，负责具体数据的生成
     * @return 反馈
     */
	bool CreateDataTask(DataProvider *provider);

    /*
     * @brief 获取任务的状态
     * @parm taskID
     * @return 任务状态
     */
	OWSMODULE::OWSTask GetTaskState(const std::string& taskID);


	/*
	 * @brief 获取数据的方法
     * @parm dataBlock返回数据块 
     * @parm taskID 
	 */
	int GetData(const std::string &taskID, OWSMODULE::byteSeq& dataBlock);

private:
    /*
     * @brief 根据taskID从map中获取数据节点
     * @parm taskID 任务ID
     * @return 数据节点 
     */
	DataNode* GetNodeByID(const std::string& taskID);  //根据任务ID获得任务

    /*
     * @brief 销毁一个数据节点
     * @parm taskID 任务ID
     */
	void DestroyOneNode(const std::string& taskID);	   //根据任务ID

private:
    /*
     * @brif 构造和析构方法设置成纯虚函数，实现单例模式
     */
	DataProcess();
	~DataProcess();

	static IceUtil::Mutex *dMutex;	 //单例锁
	static int num_data_process;     //引用计数，直到没有用户使用才销毁该单例

    ::std::map<const ::std::string, DataNode*> response;   //保存了所有数据节点，key taskID，value DataNode
    IceUtil::Mutex* iMutex;                                //互斥锁，操作response时需要
    threadpool<DataProvider> *OWSthreadpool;               //线程池

    static const int thread_number = 100;                  //线程池中最大线程数量
    static const int max_request = 10000;                  //线程池中最大任务数量
};

#endif
