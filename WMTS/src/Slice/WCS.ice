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
         *�����������ֽӿڣ��������˿�ʼ��ѯ����������
         */
        OWSMODULE::OWSTask GetCapabilities();   
        OWSMODULE::OWSTask DescribeCoverage(OWSMODULE::stringSeq coverages);
        OWSMODULE::OWSTask GetCoverage(CoverageParameter parameter, int level);
    };    
        
};
