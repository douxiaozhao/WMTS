#pragma once
#include "OWS.ice"

module WMTSMODULE
{
	/*
	   GetTile的参数
	*/
	struct GetTileParameter
    {
		string layer;
		string style;
		string format;
		int level;
		int row;
		int col;
	};

    /*
     * 金字塔数据的来源类型
     */
    enum SourceType
    {
        localFS,
        localDB,
        localMultiDB,
        cloud
    };

	/*
	   定义WMTS接口
	*/
	interface WMTS extends OWSMODULE::DataOperation
	{
        OWSMODULE::byteSeq getConfit(SourceType type);  // 获取服务器现有的某种数据源下支持的有哪些金字塔集合, xml 形式

        string addOneConfig(SourceType type, string config); // 为某种类型的数据源新增一种金字塔集的配置，返回一个token

		OWSMODULE::OWSTask GetCapabilities(string token); // 返回一种类型支持的所有金字塔集合

        OWSMODULE::OWSTask GetTile(string token, GetTileParameter parameter); // 根据token，获取相应金字塔集合的某个金字塔的瓦片

        OWSMODULE::OWSTask GetFeatureInfo(string token, GetTileParameter parameter, int I, int J, string information);
	};
};
