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
        LOCALFS,
        LOCALDB,
        LOCALMULTIDB,
        CLOUD
    };

    /*
     * �������еĽ�����������
     */
    struct PyramidCollection
    {
        string pyramidName;
        string token;
    };
    sequence<PyramidCollection> pyramidSeq;

	/*
	   ����WMTS�ӿ�
	*/
	interface WMTS extends OWSMODULE::DataOperation
	{
        pyramidSeq getConfig(SourceType type);  // ��ȡ���������е�ĳ������Դ��֧�ֵ��н�������

		OWSMODULE::OWSTask GetCapabilities(string token); // ����һ������֧�ֵ����н���������

        OWSMODULE::OWSTask GetTile(string token, GetTileParameter parameter); // ����token����ȡ��Ӧ���������ϵ�ĳ������������Ƭ

        OWSMODULE::OWSTask GetFeatureInfo(string token, GetTileParameter parameter, int I, int J, string information);
	};
};
