#ifndef ENGINE_TILE_PROVIDER_H
#define ENGINE_TILE_PROVIDER_H

//������Ƭ�ṩ��

#include "../Data/SingleBufNode.h"
#include "../Data/DataProvider.h"
#include "WMTSI.h"
#include <string>

/*
 * @brief TileEngine��Ƭ�ṩ��
 */
class EngineTileProvider : public DataProvider
{
public:
    /*
     * @brief ���캯��
     * @parm  ���ݿ�ڵ�
     */
	EngineTileProvider(const std::string &, const std::string &, int, int, int, SingleBufNode*, PyramidStore*);

	virtual ~EngineTileProvider();

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
    const std::string layer, format;
    int level, x, y;
	SingleBufNode *node;                     //���ݿ�ڵ� 
	PyramidStore *store;
	static const int BUFSIZE  = 1024 * 10;
};

#endif
