#pragma once
#include <WMTS.h>
#include <string>
#include <map>
#include "../Data/DataProcess.h"
#include <TileEngine.h>
#include <IceUtil/Mutex.h>

/*
	WMTS�ӿڵľ���ʵ��
*/
class WMTSI :public ::WMTSMODULE::WMTS
{
public:
	WMTSI(const ::std::string&, const ::std::string& );
	~WMTSI(void);

	/*
     * @brief ��ȡĳһ������Դ���͵�����������Ϣ
     * @parm type ����������Դ����
	 */
	virtual OWSMODULE::byteSeq getConfig(::WMTSMODULE::SourceType type, const ::Ice::Current& c);

    /*
     * @brief ���һ���µ�����
     * @parm type ����������Դ����
     * @parm config ����
     * @return ��ʾ�����õ�token��Ϣ
     */
	std::string addOneConfig(::WMTSMODULE::SourceType type, const ::std::string& config, const ::Ice::Current& c);

    /*
     * @brief GetCapabilities
     * @parm token ��ʾһ�ݽ�������������
     * @parm Ice����ʱ
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetCapabilities(const ::std::string& token, const ::Ice::Current& c);

    /*
     * @brief GetTile
     * @parm token ��ʾһ�ݽ�������������
     * @parm parm ��ȡ��Ƭ�Ĳ���
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetTile(const ::std::string& token, const ::WMTSMODULE::GetTileParameter& parm, const ::Ice::Current& c);

    /*
     * @brief GetFeatureInfo
     * @parm token ��ʾһ�ݽ�������������
     * @return ����һ������
     */
	virtual ::OWSMODULE::OWSTask GetFeatureInfo(const ::std::string& token, const ::WMTSMODULE::GetTileParameter& parm, ::Ice::Int I, ::Ice::Int J, const ::std::string& informantion, const ::Ice::Current& c);

    /*
     * @brief �������״̬
     * @parm string ����IDkkk
     * @parm task д������
     */
	virtual void CheckState(const ::std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Current& c);
    /*
     * @brief ��ȡ������ݿ�
     * @parm string ����ID
     * @parm byteSeq ������ݿ�
     */
	virtual ::Ice::Int ReadData(const ::std::string& taskID, ::OWSMODULE::byteSeq& data, const ::Ice::Current& c);

    /*
     * @brief �˳�����
     */
	virtual void shutdown(const ::Ice::Current& c);

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
	std::map<std::string, std::string> store_info;    // �����������Դ�Ľ������ֿ��������Ϣ

    IceUtil::Mutex* iMutex;                           //������������responseʱ��Ҫ
};
