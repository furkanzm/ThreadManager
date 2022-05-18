#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std::chrono_literals;

class ThreadManager
{
public:
    
	ThreadManager();
	~ThreadManager();
	void start();							// başlayacak
	void stop(); // duracak, kullanıcı istediğinidede durdurabilecek.
	void setFunc(std::function<int(void)> cb); // iş görecek funksiyon
	void setInterval(int x);				   // ne kadar çalışacak
	void wait();   // kendi kendine bitmesini bekleyeceğiz
	void notify(); // tekrar başlama
    void spin();
private:
    int i ;
    int buffer = 0;
	int miliSecond = 100;
	std::function<int()> cb;
	void worker();
	std::thread *thread_object;
	std::mutex mtx;
	std::condition_variable stoper;
    std::unique_lock<std::mutex> lock{ mtx };    
	bool stopped = false;
	bool sFlag;
  //  int i = 0;

};
