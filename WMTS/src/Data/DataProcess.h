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
 * @brief ���ݴ���������һ������
 */
class DataProcess
{
public:
	static DataProcess* uniqueInstance;            //����ָ��
	static DataProcess* getInstance();             //���ص���
	static void destroyInstance();                 //����ʵ��

    /*
     * @brief ����һ����������
     * @parm provider �����ṩ�࣬����������ݵ�����
     * @return ����
     */
	bool CreateDataTask(DataProvider *provider);

    /*
     * @brief ��ȡ�����״̬
     * @parm taskID
     * @return ����״̬
     */
	OWSMODULE::OWSTask GetTaskState(const std::string& taskID);


	/*
	 * @brief ��ȡ���ݵķ���
     * @parm dataBlock�������ݿ� 
     * @parm taskID 
	 */
	int GetData(const std::string &taskID, OWSMODULE::byteSeq& dataBlock);

private:
    /*
     * @brief ����taskID��map�л�ȡ���ݽڵ�
     * @parm taskID ����ID
     * @return ���ݽڵ� 
     */
	DataNode* GetNodeByID(const std::string& taskID);  //��������ID�������

    /*
     * @brief ����һ�����ݽڵ�
     * @parm taskID ����ID
     */
	void DestroyOneNode(const std::string& taskID);	   //��������ID

private:
    /*
     * @brif ����������������óɴ��麯����ʵ�ֵ���ģʽ
     */
	DataProcess();
	~DataProcess();

	static IceUtil::Mutex *dMutex;	 //������
	static int num_data_process;     //���ü�����ֱ��û���û�ʹ�ò����ٸõ���

    ::std::map<const ::std::string, DataNode*> response;   //�������������ݽڵ㣬key taskID��value DataNode
    IceUtil::Mutex* iMutex;                                //������������responseʱ��Ҫ
    threadpool<DataProvider> *OWSthreadpool;               //�̳߳�

    static const int thread_number = 100;                  //�̳߳�������߳�����
    static const int max_request = 10000;                  //�̳߳��������������
};

#endif
