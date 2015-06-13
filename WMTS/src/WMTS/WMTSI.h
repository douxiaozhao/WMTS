#pragma once
#include <WMTS.h>
#include <string>
#include <map>
#include "../Data/DataProcess.h"
#include <TileEngine.h>
/*
	WMTS接口的具体实现
*/
class WMTSI :public ::WMTSMODULE::WMTS
{
public:
	WMTSI(const ::std::string&, const ::std::string& );
	~WMTSI(void);

	/*
	 */
	virtual OWSMODULE::byteSeq getConfit(::WMTSMODULE::SourceType, const ::Ice::Current& );

	std::string addOneConfig(::WMTSMODULE::SourceType, const ::std::string&, const ::Ice::Current& /* = ::Ice::Current */);

    /*
     * @brief GetCapabilities
     * @parm Ice运行时
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetCapabilities(const ::std::string&, const ::Ice::Current&);

    /*
     * @brief GetTile
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetTile(const ::std::string&, const ::WMTSMODULE::GetTileParameter&, const ::Ice::Current&);

    /*
     * @brief GetFeatureInfo
     * @return 返回一个任务
     */
	virtual ::OWSMODULE::OWSTask GetFeatureInfo(const ::std::string&, const ::WMTSMODULE::GetTileParameter&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current&);

    /*
     * @brief 检查任务状态
     * @parm string 任务ID
     * @parm task 写入任务
     */
	virtual void CheckState(const ::std::string&, ::OWSMODULE::OWSTask&, const ::Ice::Current&);
    /*
     * @brief 读取结果数据块
     * @parm string 任务ID
     * @parm byteSeq 结果数据块
     */
	virtual ::Ice::Int ReadData(const ::std::string&, ::OWSMODULE::byteSeq&, const ::Ice::Current&);
											 
    /*
     * @brief 退出服务
     */
	virtual void shutdown(const ::Ice::Current&);

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
};
