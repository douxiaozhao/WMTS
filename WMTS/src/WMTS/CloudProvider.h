#pragma once

#include "../Data/DataProvider.h"
#include "../Data/SingleBufNode.h"
#include <string>

/*
 * @brief �ƶ���Ƭ�ṩ�࣬ͨ��http�����ȡ��Ƭ
 */
class CloudProvider : public DataProvider
{
public:
	CloudProvider(const char*, int , int, int, SingleBufNode* );
	~CloudProvider(void);
	/*
	 * @brief �̳߳�ģ����ú���
	 */
	virtual void process();

	/*
	 * @brief: ��ȡ���ݽڵ�
	 * @return: �������ݿ�ڵ�
	 */
	virtual DataNode* GetDataNode();

private:
	/*
	 * @brief: ��ȡ��Ƭ
	 */
	virtual void getTile();
	/*
	 * @brief: C++�����������ص��ӿ�
	 * @return: �������ݿ鳤��
	 */
	static size_t WriteMemoryCallback(void *, size_t, size_t, void *);

private:
	const std::string layer;            //ͼ��
	int level, x, y;					//�ȼ���x��y
	SingleBufNode *node;                //���ݿ�ڵ� 
};

