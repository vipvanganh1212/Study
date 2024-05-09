#include <iostream>
#include <thread>
#include "Signal.h"
#include <chrono>
#include <functional>
#include "joining_thread.h"
#include "threadguard.h"

int game = 10;

void displayVariable(int& a, int &b)
{
	a = 20;
	std::cout << "Current value is : " << game << std::endl;
}

Thread_Guard do_task()
{
	 std::thread* actionT =  new std::thread(([]() {
		Signal aSignal;
		}));
	return Thread_Guard(actionT);
}

int main()
{
	//{
	//	int game2 = 10;
	//	do_task();
	//	Thread_Guard athread(new std::thread(std::bind(displayVariable, std::ref(game), std::ref(game2)))); 
	//}

	{
		joining_thread jthread([&](int a, int b, int c) {
			Thread_Guard aaa = do_task();
			std::cout << "a: " << a << " \nb:  " << b << " \nc: " << c << std::endl;
			},12,13,14);
	}


	while (true)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1000ms);
		std::cout << " the circle is running!!!" << std::endl;
	}

	return 0;
}