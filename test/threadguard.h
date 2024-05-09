#ifndef _THREAD_GUARD
#define _THREAD_GUARD
#include <thread>
#include <iostream>
class Thread_Guard
{
public:
	explicit Thread_Guard(std::thread* _t);
	~Thread_Guard();
private:
	std::thread* t;
};

#endif // !_THREAD_GUARD

inline Thread_Guard::Thread_Guard(std::thread* _t): t(_t)
{
	// do nothing
}

inline Thread_Guard::~Thread_Guard()
{
	std::cout << "Thread guard destructor" << std::endl;
	if (t->joinable())
	{
		t->join();
	}
	delete t;
}

