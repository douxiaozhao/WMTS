#pragma once
#include <WMTS.h>
#include <string>
#include <map>
#include "../Data/DataProcess.h"
#include <TileEngine.h>
#include <IceUtil/Mutex.h>

/*
	WMTS接口的具体实现
*/
class WMTSI :public ::WMTSMODULE::WMTS
{
public:
	WMTSI(const ::std::string&, const ::std::string& );
	~WMTSI(void);

	/*
     * @brief 获取某一种数据源类型的所有配置信息
     * @parm type 金字塔数据源类型
	 */
	virtual OWSMODULE::byteSeq getConfig(::WMTSMODULE::SourceType type, const ::Ice::Current& c);

    /*
     * @brief 添加一个新的配置
     * @parm type 金字塔数据源类型
     * @parm config 配置
     * @return 表示该配置的token信息
     */
	std::string addOneConfig(::WMTSMODULE::SourceType type, const ::std::string& config, const ::Ice::Current& c);

    /*
     * @brief GetCapabilities
     * @parm token 表示一份金字塔集的配置
     * @parm Ice运行时
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetCapabilities(const ::std::string& token, const ::Ice::Current& c);

    /*
     * @brief GetTile
     * @parm token 表示一份金字塔集的配置
     * @parm parm 获取瓦片的参数
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetTile(const ::std::string& token, const ::WMTSMODULE::GetTileParameter& parm, const ::Ice::Current& c);

    /*
     * @brief GetFeatureInfo
     * @parm token 表示一份金字塔集的配置
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetFeatureInfo(const ::std::string& token, const ::WMTSMODULE::GetTileParameter& parm, ::Ice::Int I, ::Ice::Int J, const ::std::string& informantion, const ::Ice::Current& c);

    /*
     * @brief 检查任务状态
     * @parm string 任务IDkkk
     * @parm task 写入任务
     */
	virtual void CheckState(const ::std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Current& c);
    /*
     * @brief 读取结果数据块
     * @parm string 任务ID
     * @parm byteSeq 结果数据块
     */
	virtual ::Ice::Int ReadData(const ::std::string& taskID, ::OWSMODULE::byteSeq& data, const ::Ice::Current& c);

    /*
     * @brief 退出服务
     */
	virtual void shutdown(const ::Ice::Current& c);

private:
	/*
	 * @brief 初始化服务，设置TileEngine支持的数据源
	 * @parm 配置文件的绝对路径
	 */
	void initServer(const std::string&);

private:
	const std::string _name;						  // 服务名称
	DataProcess *data_process;			              // 数据处理过程

	std::map<std::string, PyramidStore*> store_list;  // 保存各种数据源的金字塔仓库, 分别保存金字塔仓库和对应的类型
	std::map<std::string, std::string> store_info;    // 保存各种数据源的金字塔仓库的配置信息

    IceUtil::Mutex* iMutex;                           //互斥锁，操作response时需要
};
