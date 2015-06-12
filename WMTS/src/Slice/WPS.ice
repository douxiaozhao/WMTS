#pragma once 
#include "OWS.ice"

module WPSMODULE
{
	enum UploadState       		   //�������ص�״̬ 
    {
        UPLOADING,				   /** 0 �����ϴ�*/
        UPLOADFINISH,	           /** 1 �ϴ����*/
		UPLOADCANCEL			   /** 2 ȡ���ϴ�*/
    };

	//WPS����		
    interface WPS extends OWSMODULE::DataOperation{
		OWSMODULE::OWSTask CoordinateTransformation(string original, string target, string fileFormat);   //���߷�����Դ����ϵҲĿ������ϵ, ����ļ���ʽ
		bool UploadFile(string taskID, OWSMODULE::byteSeq dataBlock, int len, UploadState state);  //taskID, �ϴ����ݿ飬 ���ȣ� �ϴ�״̬
	};
};
