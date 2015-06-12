#include "SingleBufNode.h"

SingleBufNode::SingleBufNode() : buf(NULL), len(0), pos(0), buf_size(0)
{
}

SingleBufNode::~SingleBufNode()
{
	//std::cout << "free SingleBufNode!" << std::endl;
	free(buf);
}

bool SingleBufNode::AllocateMem( int size )
{
	if(size <= 0)
		return false;
	buf = (unsigned char*)realloc(buf, buf_size+size);
	memset(buf+buf_size, 0, size);
	buf_size += size;
	return true;
}

int SingleBufNode::GetData( OWSMODULE::byteSeq& dataBlock )
{
	if(pos >= len)
		return 0;
	int num = READSIZE;
	if(num >= len - pos)
		num = len - pos;
	dataBlock.assign(buf+pos, buf+pos+num);
	pos += num;
	if(pos >= len)
		SetTaskState(OWSMODULE::OWSFINISH);
	return num;
}

unsigned char* SingleBufNode::GetBuf()
{
	return buf;
}

void SingleBufNode::SetLen( int len )
{
	this->len = len;
}

int SingleBufNode::GetLen()
{
	return len;
}
