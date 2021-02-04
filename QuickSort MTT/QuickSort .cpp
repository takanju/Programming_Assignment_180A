/*
 * QuickSort .cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: swapnanjali
 */

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>

using namespace std;

//print array
template <typename T>
void print(const vector<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

//queue tasks
queue< pair<int, int> > tasks;
//mutexs for set and queue task
mutex q_mutex, s_mutex;
//condition variable
condition_variable cv;

//set
set<int> ss;



//https://stackoverflow.com/questions/37334109/quick-sort-with-multithreading-in-c

//partition algorithm
template <typename T>
int partition(vector<T> &arr, int l, int r)
{
    T tmp = arr[r]; //as pivot element
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
            if (arr[j] < tmp)
            {
                i++;
                swap(arr[i], arr[j]);
            }

        swap(arr[i + 1], arr[r]);
        i++;
        return i;
    }

    //quick sort
    template <typename T>
    void quick_sort(vector<T> &arr)
    {
        while (true)
        {
            unique_lock<mutex> u_lock(q_mutex); //lock mutex

            //sort is fineshed
            if ( ss.size() == arr.size() ) //u_lock.unlock()
                return;

            //if queue task is not empty
            if ( tasks.size() > 0 )
            {
                //get task from queue
                pair<int, int> cur_task;
				int l = cur_task.first, r = cur_task.second;

				            if (l < r)
				            {
				                int q = partition(arr, l, r); //split array

				                //Add indexes in set
				                s_mutex.lock();
				                ss.insert(q);
				                ss.insert(l);
				                ss.insert(r);
				                s_mutex.unlock();

				                //push new tasks for left and right part
				                tasks.push( make_pair(l, q - 1) );
				                tasks.push( make_pair(q + 1, r) );

				                //wakeup some thread which waiting
				                cv.notify_one();
				            }
				        }
				        else
				            //if queue is empty
				            cv.wait(u_lock);
				    }
				}

    //Size array
    const int ARR_SIZE = 100000;
    //Count threads
    const int THREAD_COUNT = 8;

    thread thrs[THREAD_COUNT];

    //generatin array
    void generate_arr(vector<int> &arr)
    {
        srand(time( NULL ));

        std::generate(arr.begin(), arr.end(), [](){return rand() % 10000; });
    }

    //check for sorting
    bool is_sorted(const vector<int> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
            if ( ! (arr[i] <= arr[i + 1]) )
                return false;
        return true;
    }



    int main()
    {
        //time
        clock_t start, finish;

        vector<int> arr(ARR_SIZE);

        //generate array
        generate_arr(arr);

        cout << endl << "Generating finished!" << endl << endl;

        cout << "Array before sorting" << endl << endl;

        //Before sorting
        print(arr);

        cout << endl << endl;

        cout << "Checking is_sorted finished! The result is " << (is_sorted(arr) == 0? "false": "true") << "." << endl << endl;

        //add task
        tasks.push( make_pair(0, arr.size() - 1) );

        //==================================================
        start = clock();

        for (int i = 0; i < THREAD_COUNT; i++)
                    thrs[i] = thread( quick_sort<int>, ref(arr) );

                finish = clock();
            //==================================================

            for (auto& th : thrs)
                th.join();

            cout << "Sorting finished!" << endl << endl;

            cout << "Array after sorting" << endl << endl;
            //After sorting
            print(arr);

            cout << endl << endl;

            cout << "Checking is_sorted finished! The result is " << (is_sorted(arr) == 0? "false": "true") << "." << endl << endl;

            cout << "Runtime: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;

            return 0;
        }

