#include "DataProcess.h"
#include <IceUtil\Cond.h>

DataProcess* DataProcess::uniqueInstance = NULL;
IceUtil::Mutex* DataProcess::dMutex = new IceUtil::Mutex();
int DataProcess::num_data_process = 0;

DataProcess::DataProcess() : response(), iMutex(new IceUtil::Mutex), OWSthreadpool(new threadpool<DataProvider>(thread_number, max_request))
{
}

DataProcess::~DataProcess()
{
	delete(OWSthreadpool); //先删除线程池，再销毁数据节点的map表，注意，顺序不能反
    iMutex->lock();
    for(::std::map<const ::std::string, DataNode*>::iterator iter = response.begin(); iter != response.end(); ++iter)
        delete(iter->second);
    iMutex->unlock();
    delete(iMutex);
}

bool DataProcess::CreateDataTask(DataProvider *provider)
{
    DataNode *node = provider->GetDataNode();

    iMutex->lock();
    response.insert(make_pair(node->GetTaskID(), node));
    iMutex->unlock();

    if(OWSthreadpool->append(provider) == false)
    {
        iMutex->lock();
        response.erase(node->GetTaskID());
        iMutex->unlock();
		return false;
    }
	return true;
}

OWSMODULE::OWSTask DataProcess::GetTaskState( const std::string& taskID )
{
	OWSMODULE::OWSTask task;
	task.taskID = taskID;

	DataNode* node = GetNodeByID(taskID);
	if(node == NULL)
	{
		task.state = OWSMODULE::OWSERROR;
		return task;
	}

	task.state = node->GetTaskState();
	
	if(task.state == OWSMODULE::OWSFINISH)
	{	
#ifdef DEBUG
		std::cout << "clear one node " << std::endl;
#endif
		delete(node);
		DestroyOneNode(taskID);
	}
#ifdef DEBUG
	std::cout << taskID << " " << task.state << std::endl;
#endif
	return task;
}

int DataProcess::GetData( const std::string &taskID, OWSMODULE::byteSeq& dataBlock )
{
	DataNode* node = GetNodeByID(taskID);
	return node->GetData(dataBlock);
}

DataNode* DataProcess::GetNodeByID( const std::string& taskID )
{
	IceUtil::Mutex::Lock lock(*iMutex);
	std::map<const std::string, DataNode* >::iterator iter = response.find(taskID);
	if(iter == response.end())
		return NULL;
	DataNode *node = iter->second;
	return node;
}

void DataProcess::DestroyOneNode( const std::string& taskID )
{
	IceUtil::Mutex::Lock lock(*iMutex);
	response.erase(taskID);
}

DataProcess* DataProcess::getInstance()
{
	IceUtil::Mutex::Lock lock(*dMutex);
	++num_data_process;
	if(uniqueInstance == NULL)
		uniqueInstance = new DataProcess();
	return uniqueInstance;
}

void DataProcess::destroyInstance()
{
	IceUtil::Mutex::Lock lock(*dMutex);
	--num_data_process;
	if(num_data_process == 0 && uniqueInstance != NULL){
		std::cout << "destroy data process " << std::endl;
		delete uniqueInstance;
		uniqueInstance = NULL;
	}
}