#pragma once
#include "OWS.ice"

module WMSMODULE
{
	/*
	   GetMap的参数
	*/
	struct GetMapParameter{
        OWSMODULE::stringSeq layers;
        OWSMODULE::stringSeq styles;
		string CRS;
		OWSMODULE::BBOX box;
        int width;
        int height;
		string format;
	};

	struct GetFeatureInfoParameter{
		GetMapParameter mparameter;
		OWSMODULE::stringSeq layers;
		string fromat;
		int I;
		int J;
	};

	/*
	   定义WMS接口
	*/
	interface WMS extends OWSMODULE::DataOperation
	{
		OWSMODULE::OWSTask GetCapabilities();          
        OWSMODULE::OWSTask GetMap(GetMapParameter parameter);
        OWSMODULE::OWSTask GetFeatureInfo(GetFeatureInfoParameter parameter);
	};
};
