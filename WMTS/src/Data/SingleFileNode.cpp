#include "SingleFileNode.h"
#include "stdio.h"


SingleFileNode::SingleFileNode() : fileName(""), len(0), pos(0), buf(new unsigned char[READSIZE])
{
}

SingleFileNode::~SingleFileNode()
{
	delete[] buf;
	remove(fileName.c_str());
}

int SingleFileNode::GetData( OWSMODULE::byteSeq& dataBlock )
{
	if(pos >= len)
		return 0;
	int num = READSIZE;
	if(num >= len - pos)
		num = len - pos;

	FILE *fin = NULL;
	errno_t err = fopen_s(&fin, fileName.c_str(), "rb");
	if(err == 0)
	{
		fseek(fin, pos, SEEK_SET);
		memset(buf, 0, num);
		fread(buf, 1, num, fin);
		dataBlock.assign(buf, buf+num);
		fclose(fin);
	}
	else
	{
		SetTaskState(OWSMODULE::OWSERROR);
		return 0;
	}
	
	pos += num;
	if(pos >= len)
		SetTaskState(OWSMODULE::OWSFINISH);
	return num;
}

void SingleFileNode::SetFileName( std::string& fileName )
{
	this->fileName = fileName;
}


std::string SingleFileNode::GetFileName()
{
	return fileName;
}


void SingleFileNode::SetFileLen( int len )
{
	this->len = len;
}
