#include "DataNode.h"

DataNode::DataNode()
{
    mutex = new IceUtil::Mutex;
    task = new OWSMODULE::OWSTask;
}

DataNode::~DataNode()
{
    delete(mutex);
    delete(task);
}

std::string DataNode::GetTaskID()								  
{
    return task->taskID;
}

void DataNode::SetTaskID(const std::string& taskID)
{
    task->taskID = taskID;
}

OWSMODULE::OWSState DataNode::GetTaskState()                      
{
    IceUtil::Mutex::Lock lock(*mutex);
    return task->state;
}

void DataNode::SetTaskState(OWSMODULE::OWSState state)             
{
    IceUtil::Mutex::Lock lock(*mutex);
    task->state = state;
}

void DataNode::setTaskLength( int length )
{
	task->length = length;
}
