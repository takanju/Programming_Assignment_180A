/*
 * QueueNoSync.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: swapnanjali
 */




#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <time.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;




mutex mu;
condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize=50;


void producer(int val){
	while(val){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, [](){return buffer.size() < maxBufferSize;});
		buffer.push_back(val);
		cout<<"Produced: "<< val<<endl;
		val--;
		locker.unlock();
		cond.notify_one();

	}

}

void consumer(int val){
	while(true){
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, [](){return buffer.size() > 0;});
		int val = buffer.back();
		buffer.pop_back();
		cout<<"consumed: "<<val<<endl;
		locker.unlock();
		cond.notify_one();

	}

}



int main()
{
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}
