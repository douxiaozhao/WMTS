#ifndef SINGLE_BUF_NODE_H
#define SINGLE_BUF_NODE_H

#include "DataNode.h"

/*
 * @brief 单独内存数据块，数据结果存在一整块内存块中
 */
class SingleBufNode : public DataNode
{
public:
	SingleBufNode();
	virtual ~SingleBufNode();

	/*
	 * @brief 获取数据的方法
     * @parm dataBlock 结果写入该数据块中 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock);

	/*
	 * @brief 分配内存，递增式分配内存
     * @parm size分配的内存的大小
     * @return 反馈结果
	 */
	bool AllocateMem(int size);	   //为buf分配内存

	/*
	 * @brief 获取内存指针
     * @return 返回内存指针
	 */
	unsigned char* GetBuf();	   //获得buf

	/*
	 * @brief 设置内存块长度 
     * @parm len 长度
	 */
	void SetLen(int len);		   //设置buf长度

	/*
	 * @brief 获取内存块长度 
     * @return 长度
	 */
	int GetLen();				   //获取buf的长度	

private:
	unsigned char* buf;				//buf
	int len, pos, buf_size;			//buf长度，读取位置指针, buf共分配的内存大小
	static const int READSIZE = 1024*1024;   //一次读取长度
};

#endif
