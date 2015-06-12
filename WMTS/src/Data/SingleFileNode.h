#ifndef SINGLE_BUF_NODE_H
#define SINGLE_BUF_NODE_H

#include "DataNode.h"
#include <string>

/*
 * @brief 单独文件数据块，数据结果存在一整个文件中
 */
class SingleFileNode : public DataNode
{
public:
	SingleFileNode();
	virtual ~SingleFileNode();

	/*
	 * @brief 获取数据的方法
     * @parm dataBlock 结果写入该数据块中 
	 */
	virtual int GetData(OWSMODULE::byteSeq& dataBlock);

	/*
	 * @brief 设置文件名称
     * @parm fileName 文件名称
	 */
	void SetFileName(std::string& fileName);

	/*
	 * @brief 获取文件名称
     * @return 文件名称
	 */
	std::string GetFileName();

	/*
	 * @brief 设置文件长度
     * @parm len 文件长度
	 */
	void SetFileLen(int len);

private:
	std::string fileName;        //文件名称
	int len, pos;                //文件长度，当前读到的位置
	static const int READSIZE = 1024*1024;
	unsigned char* buf;          //从文件中读出的数据临时缓冲区
};


#endif
