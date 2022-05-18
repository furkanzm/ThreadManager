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
	work.setInterval(1000); // second
	work.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // millisecond
	//work.stop();
	work.notify();
	std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // millisecond
	return 0;
}
