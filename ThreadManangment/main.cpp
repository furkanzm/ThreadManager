#include "threadmanager.h"

int i = 0;
int run()
{

	i += 1;
	std::cout << "Asking Worker to Stop  " << i << std::endl;

	if (i > 10)
		return -1;

	return 0;
}

int main()
{
	ThreadManager work;
	work.setFunc(run);
	work.setInterval(1); // saniye
	work.start();
	// work.wait();

	// work.notify();

	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // milisaniye
	// work.stop();
	work.stop();
	std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // milisaniye
	return 0;
}
