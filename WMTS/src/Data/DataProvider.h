#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include <map>
#include <string>
#include <IceUtil/Mutex.h>
#include <OWS.h>
#include "DataNode.h"

/*
 * @brief �����ṩ�࣬������
 */
class DataProvider
{
public:
	virtual ~DataProvider(){};
    /*
     * @brief �̳߳�ģ����øú�����ִ�о���������ɾ�������ʵ��
     */
	virtual void process() = 0;

    /*
     * @brief ��ȡ���ݽڵ�
     * @return ���ݽڵ�
     */
    virtual DataNode* GetDataNode() = 0;
};

#endif
