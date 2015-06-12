#pragma once
#include "OWS.ice"

module WMTSMODULE
{
	/*
	   GetTile�Ĳ���
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
	   ����WMTS�ӿ�
	*/
	interface WMTS extends OWSMODULE::DataOperation
	{
		OWSMODULE::OWSTask GetCapabilities();          
        OWSMODULE::OWSTask GetTile(GetTileParameter parameter);
        OWSMODULE::OWSTask GetFeatureInfo(GetTileParameter parameter, int I, int J, string information);
	};
};
