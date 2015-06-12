#pragma once
#include <WMTS.h>
#include <string>
#include <map>
#include "../Data/DataProcess.h"
#include <TileEngine.h>
/*
	WMTS�ӿڵľ���ʵ��
*/
class WMTSI :public ::WMTSMODULE::WMTS
{
public:
	WMTSI(const ::std::string&, const ::std::string& );
	~WMTSI(void);

    /*
     * @brief GetCapabilities
     * @parm Ice����ʱ
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetCapabilities(const ::Ice::Current&);

    /*
     * @brief GetTile
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetTile(const ::WMTSMODULE::GetTileParameter&, const ::Ice::Current&);

    /*
     * @brief GetFeatureInfo
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetFeatureInfo(const ::WMTSMODULE::GetTileParameter&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current&);

    /*
     * @brief �������״̬
     * @parm string ����ID
     * @parm task д������
     */
	virtual void CheckState(const ::std::string&, ::OWSMODULE::OWSTask&, const ::Ice::Current&);
    /*
     * @brief ��ȡ������ݿ�
     * @parm string ����ID
     * @parm byteSeq ������ݿ�
     */
	virtual ::Ice::Int ReadData(const ::std::string&, ::OWSMODULE::byteSeq&, const ::Ice::Current&);
											 
    /*
     * @brief �˳�����
     */
	virtual void shutdown(const ::Ice::Current&);

private:
	/*
	 * @brief ��ʼ����������TileEngine֧�ֵ�����Դ
	 * @parm �����ļ��ľ���·��
	 */
	void initServer(const std::string&);

private:
	const std::string _name;						  // ��������     
	DataProcess *data_process;			              // ���ݴ������ 

	std::map<std::string, PyramidStore*> store_list;  // �����������Դ�Ľ������ֿ�, �ֱ𱣴�������ֿ�Ͷ�Ӧ������
};
