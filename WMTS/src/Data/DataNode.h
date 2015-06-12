#ifndef DATA_NODE_H
#define DATA_NODE_H

#include <OWS.h>
#include <IceUtil/Mutex.h>
#include <string>
//#define DEBUG

//#include <vld.h>

/*
 * @brief 数据节点类
 */
class DataNode{
public:
	DataNode();
	/*
	 * @brief 销毁数据,销毁锁和任务
	 */
	virtual ~DataNode();

	/*
	 * @brief 获取任务ID
     * @return taskID
	 */
	std::string GetTaskID();                       

	/*
	 * @brief 设置taskID
     * @parm taskID
	 */
	void SetTaskID(const std::string& taskID);

	/*
	 * @brief 获取任务的状态
     * @return 任务状态
	 */
	OWSMODULE::OWSState GetTaskState();	

	/*
	 * @brief 设置任务的状态
     * @parm 任务状态
	 */
	void SetTaskState(OWSMODULE::OWSState state);
    
	/*
	 * @brief 设置task里面当前可读的数据的长度, Ice客户端可以通过task结构拿到可读数据的长度
     * @parm 任务数据块的长度
	 */
	void setTaskLength(int length);

	/*
	 * @brief 获取数据的方法, 纯虚方法，需要子类具体实现
     * @parm 返回数据块 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock) = 0; 							

private:
	IceUtil::Mutex *mutex;         //互斥锁
	OWSMODULE::OWSTask *task;      //任务
};

#endif
