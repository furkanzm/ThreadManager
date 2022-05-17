#include "threadmanager.h"
#include <mutex>
std::mutex mtx;
std::condition_variable stoper;
bool stopped = false;

ThreadManager::ThreadManager()
{
     
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::start()
{
   
	sFlag = true;
	std::cout << "Thread Start" << std::endl;
	thread_object = new std::thread(&ThreadManager::worker, this);
    
} // başlayacak

void ThreadManager::setFunc(std::function<int(void)> cb)
{

	this->cb = cb;
} // iş görecek funksiyon

void ThreadManager::setInterval(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(x));

} // ne kadar çalışacak

void ThreadManager::wait()
{
	std::unique_lock<std::mutex> L {mtx};
	stoper.wait(L, [&]() { return stopped; });
	if (stopped) {
		std::cout << "wait!" << std::endl;
	}

} // kendi kendine bitmesini bekleyeceğiz

void ThreadManager::notify()
{
	std::lock_guard<std::mutex> G(mtx);
	std::cout << "notify" << std::endl;
	stoper.notify_one();
} // tekrar başlama

void ThreadManager::stop()
{
	sFlag = true;
	std::cout << "Thread End" << std::endl;
} // duracak, kullanıcı istediğinide de durdurabilecek.

void ThreadManager::worker()
{
	while (sFlag) {
        
        cb();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
	}
}
