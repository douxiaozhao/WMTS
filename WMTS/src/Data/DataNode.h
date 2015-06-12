#ifndef DATA_NODE_H
#define DATA_NODE_H

#include <OWS.h>
#include <IceUtil/Mutex.h>
#include <string>
//#define DEBUG

//#include <vld.h>

/*
 * @brief ���ݽڵ���
 */
class DataNode{
public:
	DataNode();
	/*
	 * @brief ��������,������������
	 */
	virtual ~DataNode();

	/*
	 * @brief ��ȡ����ID
     * @return taskID
	 */
	std::string GetTaskID();                       

	/*
	 * @brief ����taskID
     * @parm taskID
	 */
	void SetTaskID(const std::string& taskID);

	/*
	 * @brief ��ȡ�����״̬
     * @return ����״̬
	 */
	OWSMODULE::OWSState GetTaskState();	

	/*
	 * @brief ���������״̬
     * @parm ����״̬
	 */
	void SetTaskState(OWSMODULE::OWSState state);
    
	/*
	 * @brief ����task���浱ǰ�ɶ������ݵĳ���, Ice�ͻ��˿���ͨ��task�ṹ�õ��ɶ����ݵĳ���
     * @parm �������ݿ�ĳ���
	 */
	void setTaskLength(int length);

	/*
	 * @brief ��ȡ���ݵķ���, ���鷽������Ҫ�������ʵ��
     * @parm �������ݿ� 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock) = 0; 							

private:
	IceUtil::Mutex *mutex;         //������
	OWSMODULE::OWSTask *task;      //����
};

#endif
