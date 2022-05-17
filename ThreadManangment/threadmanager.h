#include <assert.h>
#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


class ThreadManager
{
public:
    int loopTime = 0;    
    int ctrl = 0;    
    ThreadManager();
    ~ThreadManager();
    std::thread *thread_object;
    void start(); // başlayacak
    void stop();  // duracak, kullanıcı istediğinide de durdurabilecek.
    void setFunc(std::function<int(void)> cb); // iş görecek funksiyon
    void setInterval(int x);				   // ne kadar çalışacak
    void wait();   // kendi kendine bitmesini bekleyeceğiz
    void notify(); // tekrar başlama
    bool sFlag;
    void worker();
    void lock();
    void unlock();
    std::function<int(void)> cb;
};
