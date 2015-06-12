#pragma once
#include "OWS.ice"

module WFSMODULE
{
    interface WFS extends OWSMODULE::DataOperation{
        /*
         *根据下面三种接口，服务器端开始查询并生成任务
         */
        OWSMODULE::OWSTask GetCapabilitiesFile();    
        OWSMODULE::OWSTask DescribeFeatureTypeFile(string typeName);
        OWSMODULE::OWSTask GetFeatures(string typeName, OWSMODULE::BBOX box, stringSeq propertyName);
    };       
};
