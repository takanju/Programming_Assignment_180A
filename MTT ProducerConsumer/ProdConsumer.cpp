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

using namespace std;

const int MAX_SIZE  =  8;
const int MAX_COUNT = 30;

const int PRODUCE_RATE = 2;
const int CONSUME_RATE = 5;

queue<int> q;
mutex queue_mutex;

int content = 0;
int full_cycles = 0;
int empty_cycles = 0;
bool producer_done = false;

/**
 * Produce every few seconds.
 */
void producer()
{
    while (content < MAX_COUNT)
    {
        this_thread::sleep_for(std::chrono::seconds(rand()%PRODUCE_RATE));
        unique_lock<mutex> lock(queue_mutex);

        // Is the queue not full?
        if (q.size() < MAX_SIZE)
        {
            q.push(++content);
            printf("Producer: %2d (%ld)\n", content, q.size());
        }
        else
        {
            printf("Producer: FULL.\n");
            full_cycles++;
        }

        lock.unlock();
    }

    producer_done = true;
    printf("Producer: DONE.\n");
}

/**
 * Consume every few seconds.
 */
void consumer(int id)
{
    while (true)
    {
        this_thread::sleep_for(std::chrono::seconds(rand()%CONSUME_RATE));
        unique_lock<mutex> lock(queue_mutex);

        if (!q.empty())
        {
            int data = q.front();
            q.pop();

            for (int i = 1; i <= id; i++) cout << "                     ";
            printf("Consumer #%d: %2d (%ld)\n", id, data, q.size());

            lock.unlock();
        }
        else if (producer_done)
        {
            lock.unlock();
            break;
        }
        else
        {
            empty_cycles++;

            for (int i = 1; i <= id; i++) cout << "                     ";
            printf("Consumer #%d: EMPTY.\n", id);

            lock.unlock();
        }
    }

    for (int i = 1; i <= id; i++) cout << "                     ";
    printf("Consumer #%d: DONE.\n", id);
}

int main()
{
    srand(time(NULL));

    thread producer_thread(producer);
    thread consumer_thread_1(consumer, 1);
    thread consumer_thread_2(consumer, 2);
    thread consumer_thread_3(consumer, 3);

    producer_thread.join();
    consumer_thread_1.join();
    consumer_thread_2.join();
    consumer_thread_3.join();

    cout << "Program done." << endl;
    cout << full_cycles  << " full cycles." << endl;
    cout << empty_cycles << " empty cycles." << endl;

    return 0;
}
