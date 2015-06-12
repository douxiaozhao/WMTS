#ifndef ICE_WORKQUEUE_H
#define ICE_WORKQUEUE_H

#include <IceUtil/Monitor.h>
#include <list>

/*
 * @brief �������ģ��
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
     * @parm ����һ������ѡ��
     * @return ����
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
     * @brief ��ȡһ������ѡ��
     * @return ����  
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
     * @brief �˳�����ʱ��֪ͨ���е��߳�
     */
	void QueueQuit() //������Ҫ�˳��ˣ�notifyall �̣߳������Ƿֱ��˳�
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		quit = true;
		notifyAll();
	};

private:
	std::list<T*> _q;   // �����б�
	size_t max_size;    // �����б����ߴ�
	bool quit;          // �˳���ʶ
};

#endif
