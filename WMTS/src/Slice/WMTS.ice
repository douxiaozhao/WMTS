#pragma once
#include "OWS.ice"

module WMTSMODULE
{
	/*
	   GetTile的参数
	*/
	struct GetTileParameter{
		string layer;
		string style;
		string format;
		int level;
		int row;
		int col;
	};

	/*
	   定义WMTS接口
	*/
	interface WMTS extends OWSMODULE::DataOperation
	{
		OWSMODULE::OWSTask GetCapabilities();          
        OWSMODULE::OWSTask GetTile(GetTileParameter parameter);
        OWSMODULE::OWSTask GetFeatureInfo(GetTileParameter parameter, int I, int J, string information);
	};
};
