#ifndef CAPABILITIES_PROVIDER_H
#define CAPABILITIES_PROVIDER_H

//������Ƭ�ṩ��

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include "WMTSI.h"
#include <string>
#include <tinyxml.h>

/*
 * @brief �����ļ�ϵͳ��Ƭ�ṩ��
 */
class CapabilitiesProvider : public DataProvider
{
public:
    /*
     * @brief ���캯��
     * @parm  ���ݿ�ڵ�
     */
	CapabilitiesProvider(SingleBufNode*, std::map<std::string, PyramidStore*> *);

	virtual ~CapabilitiesProvider();

    /*
     * @brief �̳߳�ģ����øú�����ִ�о��������
     */
	virtual void process(); 
    /*
     * @brief ��ȡ���ݽڵ�
     * @return ���ݽڵ�
     */
	virtual DataNode* GetDataNode();

private:
    /*
     * @brief ��ȡ��Ƭ
     */
	virtual void getCapabilities();
	char* getContents(int &);
	void releaseContests(char*);
	bool insertSingleTileMatrixSet(TiXmlElement *contents, TiXmlElement *e, const std::string &);
	bool insertSingleLayer(TiXmlElement *contents, TiXmlElement *e, const std::string &);

private:
	SingleBufNode *node;							    // ���ݿ�ڵ� 
	std::map<std::string, PyramidStore*>* store_list;   // �����������Դ�Ľ������ֿ�, �ֱ𱣴�������ֿ�Ͷ�Ӧ������
	static const int BUFSIZE  = 1024 * 10;
};

#endif