#pragma once
#include "OWS.ice"

module WMTSMODULE
{
	/*
	   GetTile�Ĳ���
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
     * ���������ݵ���Դ����
     */
    enum SourceType
    {
        localFS,
        localDB,
        localMultiDB,
        cloud
    };

	/*
	   ����WMTS�ӿ�
	*/
	interface WMTS extends OWSMODULE::DataOperation
	{
        OWSMODULE::byteSeq getConfit(SourceType type);  // ��ȡ���������е�ĳ������Դ��֧�ֵ�����Щ����������, xml ��ʽ

        string addOneConfig(SourceType type, string config); // Ϊĳ�����͵�����Դ����һ�ֽ������������ã�����һ��token

		OWSMODULE::OWSTask GetCapabilities(string token); // ����һ������֧�ֵ����н���������

        OWSMODULE::OWSTask GetTile(string token, GetTileParameter parameter); // ����token����ȡ��Ӧ���������ϵ�ĳ������������Ƭ

        OWSMODULE::OWSTask GetFeatureInfo(string token, GetTileParameter parameter, int I, int J, string information);
	};
};
