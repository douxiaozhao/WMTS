#ifndef SINGLE_BUF_NODE_H
#define SINGLE_BUF_NODE_H

#include "DataNode.h"
#include <string>

/*
 * @brief �����ļ����ݿ飬���ݽ������һ�����ļ���
 */
class SingleFileNode : public DataNode
{
public:
	SingleFileNode();
	virtual ~SingleFileNode();

	/*
	 * @brief ��ȡ���ݵķ���
     * @parm dataBlock ���д������ݿ��� 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock);

	/*
	 * @brief �����ļ�����
     * @parm fileName �ļ�����
	 */
	void SetFileName(std::string& fileName);

	/*
	 * @brief ��ȡ�ļ�����
     * @return �ļ�����
	 */
	std::string GetFileName();

	/*
	 * @brief �����ļ�����
     * @parm len �ļ�����
	 */
	void SetFileLen(int len);

private:
	std::string fileName;        //�ļ�����
	int len, pos;                //�ļ����ȣ���ǰ������λ��
	static const int READSIZE = 1024*1024;
	unsigned char* buf;          //���ļ��ж�����������ʱ������
};


#endif
