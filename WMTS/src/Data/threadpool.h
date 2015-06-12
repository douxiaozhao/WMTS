#ifndef ICE_THREADPOOL_H
#define ICE_THREADPOOL_H

#include <IceUtil/Thread.h>
#include "workqueue.h"

/*
 * 线程池模板
 */
template<typename T>
class threadpool
{
public:
	threadpool(int, int);
	~threadpool();

    /*
     * @brief 添加一个任务请求
     * @parm 一个任务请求 
     */
	bool append(T* request);

    /*
     * @brief 处理任务逻辑
     */
	void run();                                              

private:
	const int m_thread_number;                               //最大线程数量
	const int m_max_requests;								 //最大请求数量
	
	std::list<IceUtil::ThreadControl> m_threads;			 //一系列线程智能指针
	Queue<T> *m_workqueue;									 //任务队列
	bool m_stop;											 //结束标识
};

template<typename T>
threadpool<T>::threadpool(int thread_number, int max_request) : m_thread_number(thread_number), m_max_requests(max_request), 
	m_stop(false), m_threads(), m_workqueue(NULL)
{
	if(thread_number <= 0 || max_request <= 0)
		throw std::exception();

	m_workqueue = new Queue<T>(m_max_requests);

	for(int i = 0; i < m_thread_number; i++)
	{
		IceUtil::ThreadPtr t = new ICEThread<T>(this);
		m_threads.push_back(t->start());
	}
};

template<typename T>
threadpool<T>::~threadpool()
{
	m_workqueue->QueueQuit();  //任务队列退出
	m_stop = true;

	for(std::list<IceUtil::ThreadControl>::iterator iter = m_threads.begin(); iter != m_threads.end(); iter++)
		iter->join();

	delete(m_workqueue);
}

template<typename T>
bool threadpool<T>::append(T* request)
{
	return m_workqueue->put(request);
}

template<typename T>
void threadpool<T>::run()
{
	while(!m_stop)
	{
		T* request = m_workqueue->get();
		if( !request )
			continue;
		request->process();
		delete(request);
	}
}

template<typename T>
class ICEThread : public IceUtil::Thread
{
public:
	ICEThread(threadpool<T> *pool) : pool(pool){};
	virtual void run()
	{
		pool->run();
	};
private:
	threadpool<T> *pool;
};

#endif
