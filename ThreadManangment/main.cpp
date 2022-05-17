#include "threadmanager.h"

int run()
{
	int i = 0;
	std::cout << " Asking Worker " << std::endl;
	if (i++ > 10)
		return -1;
	return 0;
}

int main()
{

	ThreadManager work;
	work.setFunc(run);
	work.setInterval(1); // saniye
	work.start();
	//work.wait();
	//work.stop();
	//work.notify();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // milisaniye
	return 0;
}
