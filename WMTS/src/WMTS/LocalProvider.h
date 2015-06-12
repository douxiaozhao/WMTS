#ifndef LOCAL_TILE_PROVIDER_H
#define LOCAL_TILE_PROVIDER_H

//������Ƭ�ṩ��

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include <WMTS.h>
#include <string>

/*
 * @brief �����ļ�ϵͳ��Ƭ�ṩ��
 */
class LocalProvider : public DataProvider
{
public:
    /*
     * @brief ���캯��
     * @parm ͼ�㡢��񡢸�ʽ���ȼ���x��y�����ݿ�ڵ�
     */
	LocalProvider(const std::string&, const std::string&, const std::string&, int, int, int, SingleBufNode*);

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
	virtual void getTile();

private:
	const std::string layer, style, format;  //ͼ�㡢��ʽ����ʽ
	int level, row, col;                     //�ȼ� x y
	const std::string dir;                   //��Ƭͼ������Ŀ¼

	SingleBufNode *node;                     //���ݿ�ڵ� 

	static const int BUFSIZE	     = 1024 * 10;
};

#endif
