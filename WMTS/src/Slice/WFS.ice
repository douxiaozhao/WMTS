#pragma once
#include "OWS.ice"

module WFSMODULE
{
    interface WFS extends OWSMODULE::DataOperation{
        /*
         *�����������ֽӿڣ��������˿�ʼ��ѯ����������
         */
        OWSMODULE::OWSTask GetCapabilitiesFile();    
        OWSMODULE::OWSTask DescribeFeatureTypeFile(string typeName);
        OWSMODULE::OWSTask GetFeatures(string typeName, OWSMODULE::BBOX box, stringSeq propertyName);
    };       
};
