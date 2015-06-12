#pragma once
#include "OWS.ice"

module WCSMODULE
{
	struct CoverageParameter{
		string coverage;
		string CRS;
		string RESPONSECRS;
		OWSMODULE::BBOX box;
		OWSMODULE::stringSeq time;
		OWSMODULE::stringSeq parameter;
		int width;
		int height;
		int depth;
		double resx;
		double resy;
		double resz;
		string format;
		string exceptions;
	};

    interface WCS extends OWSMODULE::DataOperation{
        /*
         *根据下面三种接口，服务器端开始查询并生成任务
         */
        OWSMODULE::OWSTask GetCapabilities();   
        OWSMODULE::OWSTask DescribeCoverage(OWSMODULE::stringSeq coverages);
        OWSMODULE::OWSTask GetCoverage(CoverageParameter parameter, int level);
    };    
        
};
