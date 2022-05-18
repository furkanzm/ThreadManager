#include "threadmanager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
	delete thread_object;
}

void ThreadManager::start()
{
	// std::lock_guard<std::mutex> guard(mtx);
	// startTime = std::chrono::steady_clock::now();
	sFlag = true;
	thread_object = new std::thread(&ThreadManager::worker, this);

} // başlayacak

void ThreadManager::setFunc(std::function<int(void)> cb)
{
	this->cb = cb;
} // iş görecek funksiyon

void ThreadManager::setInterval(int x)
{
	miliSecond *= x;

} // ne kadar çalışacak

void ThreadManager::wait()
{
	/*std::unique_lock<std::mutex> L {mtx};
	stoper.wait(L, [&]() { return stopped; });
	if (stopped) {
		std::cout << "wait!" << std::endl;
	}*/
	thread_object->join();
} // kendi kendine bitmesini bekleyeceğiz

void ThreadManager::notify()
{
	std::unique_lock<std::mutex> lck(mtx);
	while (stoper.wait_for(lck, std::chrono::seconds(miliSecond)) ==
		   std::cv_status::timeout) {
		std::cout << '.' << std::endl;
	}
} // tekrar başlama

void ThreadManager::stop()
{
	sFlag = false;
	stoper.notify_one();
	std::cout << "thread exit" << std::endl;

} // duracak, kullanıcı istediğinide de durdurabilecek.
void ThreadManager::spin()
{
	const int work = 1000 * 1000 * 40;
	volatile int v = 0;
	for (int j = 0; j < work; ++j)
		++v;
}

void ThreadManager::worker()
{
	while (sFlag) {

		int temp = cb();
		if (temp)
			break;
		spin();
		// lck.unlock();
	}
}
