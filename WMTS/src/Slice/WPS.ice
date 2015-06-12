#pragma once 
#include "OWS.ice"

module WPSMODULE
{
	enum UploadState       		   //数据上载的状态 
    {
        UPLOADING,				   /** 0 正在上传*/
        UPLOADFINISH,	           /** 1 上传完毕*/
		UPLOADCANCEL			   /** 2 取消上传*/
    };

	//WPS服务		
    interface WPS extends OWSMODULE::DataOperation{
		OWSMODULE::OWSTask CoordinateTransformation(string original, string target, string fileFormat);   //告诉服务器源坐标系也目标坐标系, 输出文件格式
		bool UploadFile(string taskID, OWSMODULE::byteSeq dataBlock, int len, UploadState state);  //taskID, 上传数据块， 长度， 上传状态
	};
};
