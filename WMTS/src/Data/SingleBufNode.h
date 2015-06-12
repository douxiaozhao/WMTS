#ifndef SINGLE_BUF_NODE_H
#define SINGLE_BUF_NODE_H

#include "DataNode.h"

/*
 * @brief �����ڴ����ݿ飬���ݽ������һ�����ڴ����
 */
class SingleBufNode : public DataNode
{
public:
	SingleBufNode();
	virtual ~SingleBufNode();

	/*
	 * @brief ��ȡ���ݵķ���
     * @parm dataBlock ���д������ݿ��� 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock);

	/*
	 * @brief �����ڴ棬����ʽ�����ڴ�
     * @parm size������ڴ�Ĵ�С
     * @return �������
	 */
	bool AllocateMem(int size);	   //Ϊbuf�����ڴ�

	/*
	 * @brief ��ȡ�ڴ�ָ��
     * @return �����ڴ�ָ��
	 */
	unsigned char* GetBuf();	   //���buf

	/*
	 * @brief �����ڴ�鳤�� 
     * @parm len ����
	 */
	void SetLen(int len);		   //����buf����

	/*
	 * @brief ��ȡ�ڴ�鳤�� 
     * @return ����
	 */
	int GetLen();				   //��ȡbuf�ĳ���	

private:
	unsigned char* buf;				//buf
	int len, pos, buf_size;			//buf���ȣ���ȡλ��ָ��, buf��������ڴ��С
	static const int READSIZE = 1024*1024;   //һ�ζ�ȡ����
};

#endif
