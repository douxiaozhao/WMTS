#pragma once

module OWSMODULE
{
	sequence<byte> byteSeq;
	sequence<string> stringSeq;

    struct BBOX{        
        double xmin;
        double ymin;
        double xmax;
        double ymax;
    };

	/*
	   ��������״̬
	*/
	enum OWSState
    {
        OWSWAIT,           /** 0 ����׼������*/
        OWSSTART,          /** 1 ����׼��*/
        OWSFINISH,         /** 2 �������*/
        OWSERROR           /** 3 ��������*/ 
    };

	/*
	   ��������
	*/
	struct OWSTask
	{
		string taskID;               /** �����Ψһ��־�� uuid*/
        OWSState state;              /** ��ǰ��������״̬*/ 
		int length;					 /** ��ǰ�ɶ����ݵĳ���*/
	};

	/*
	   �������ݲ���
	*/
	interface DataOperation{
		/*
        *����taskID,�鿴������ǰ�Ƿ��������
        */
        void CheckState(string taskID, out OWSTask task);

        /*
         * ����taskID��������Ӧ���ļ�
         */
        int ReadData(string taskID, out byteSeq DataBlock);  //FileInfo ��ʾ��Ҫ�����ļ���Ϣ�� len��ʾ��Ҫ���ĳ���

        void shutdown();
	};
};
