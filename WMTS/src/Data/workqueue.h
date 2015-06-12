#ifndef ICE_WORKQUEUE_H
#define ICE_WORKQUEUE_H

#include <IceUtil/Monitor.h>
#include <list>

/*
 * @brief 任务队列模板
 */
template<typename T> class Queue : public IceUtil::Monitor<IceUtil::Mutex>
{
public:
	Queue(size_t size) : _q(), max_size(size), quit(false){};

	~Queue()
	{
		for(std::list<T*>::iterator iter = _q.begin(); iter != _q.end(); iter++)
			delete(*iter);
	}

    /*
     * @parm 放入一个任务选项
     * @return 反馈
     */
	bool put(T* item)
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		if(_q.size() >= max_size)
			return false;
		_q.push_back(item);
		notify();
		return true;
	};

    /*
     * @brief 获取一个任务选项
     * @return 任务  
     */
	T* get()
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		while(_q.empty() && !quit)
		
			wait();
		
		if(quit)
			return NULL;

		T* item = _q.front();
		_q.pop_front();
		return item;
	};

    /*
     * @brief 退出程序时，通知所有的线程
     */
	void QueueQuit() //主程序要退出了，notifyall 线程，让它们分别退出
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		quit = true;
		notifyAll();
	};

private:
	std::list<T*> _q;   // 任务列表
	size_t max_size;    // 任务列表最大尺寸
	bool quit;          // 退出标识
};

#endif
