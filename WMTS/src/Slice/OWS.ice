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
	   定义任务状态
	*/
	enum OWSState
    {
        OWSWAIT,           /** 0 正在准备数据*/
        OWSSTART,          /** 1 数据准备*/
        OWSFINISH,         /** 2 传输完毕*/
        OWSERROR           /** 3 发生错误*/ 
    };

	/*
	   定义任务
	*/
	struct OWSTask
	{
		string taskID;               /** 任务的唯一标志， uuid*/
        OWSState state;              /** 当前这个任务的状态*/ 
		int length;					 /** 当前可读数据的长度*/
	};

	/*
	   定义数据操作
	*/
	interface DataOperation{
		/*
        *根据taskID,查看该任务当前是否可以下载
        */
        void CheckState(string taskID, out OWSTask task);

        /*
         * 根据taskID，下载相应的文件
         */
        int ReadData(string taskID, out byteSeq DataBlock);  //FileInfo 表示所要读的文件信息， len表示所要读的长度

        void shutdown();
	};
};
