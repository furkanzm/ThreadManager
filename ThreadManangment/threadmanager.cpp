#include "threadmanager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::start()
{
	startFlag = true;
	stopFlag = false;
	std::cout << "thread started" << std::endl;
	thread_object = new std::thread(&ThreadManager::worker, this);

} // start

void ThreadManager::setFunc(std::function<int(void)> cb)
{
	this->cb = cb;
} // set function

void ThreadManager::setInterval(int x)
{
	milliSecond = x;

} // how long is work

void ThreadManager::wait()
{
	std::cout << "thread waiting!" << std::endl;
	thread_object->join();
} // self exit wait

void ThreadManager::notify()
{
	stoper.notify_one();
} //

void ThreadManager::stop()
{
	stopFlag = true;
	std::cout << "thread stopped!" << std::endl;
	stoper.notify_all();

} // this is

void ThreadManager::worker()
{
	std::unique_lock<std::mutex> lck(mtx);

	while (1) {
		stoper.wait_for(lck, std::chrono::milliseconds(milliSecond * 100));
		if (stopFlag)
			break;
		int temp = cb();
		if (temp)
			break;
	}
	std::cout << "thread exit" << std::endl;
}
