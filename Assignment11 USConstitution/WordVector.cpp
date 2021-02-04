/*
 * WordVector.cpp
 *
 *  Created on: Nov 7, 2020
 *      Author: swapnanjali
 */


#include <vector>
#include "TimedContainer.h"
#include "Word.h"
#include "WordVector.h"
#include <iterator>
#include <algorithm>
#include <ctype.h>

using namespace std;

    int WordVector::get_count(const string text) const{

    vector<Word>::iterator it = search(text);
    if(it!=end()){
    	return it->get_count();
    }
    return 0;
    }


    void WordVector::insert(const string text){
    	steady_clock::time_point start = steady_clock::now();
    	vector<Word>::iterator it = search(text);
    	if(it->get_text()=text){
    	it->increment_count();
    		}
    	else{
    		while(it!=end())
    			if(text> it->get_text()){it++;}
    		}
    	vector<Word>::insert(it, Word(text));

    	}
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start,steady_clock::now());
          return;

    }

    vector<Word>::iterator WordVector::search(const string text){
    	steady_clock::time_point start = steady_clock::now();
    	int idx = find(text, 0, size()-1);
    	if(idx==-1){
    		return end();
    	}
    	increment_elapsed_time(start,steady_clock::now());
    	          return begin() +idx;

    }


    int WordVector::find(const string text, int low, int high) const {
          int mid = (low+high)/2;
          if(low > high) {
             return -1;
          }
          string mid_text = (vector<Word>::at(mid)).get_text();

          if(mid_text == text) {
             return mid;
          }

          if(mid_text < text) {
             return find(text, mid+1, high);
          } else {
             return find(text, low, mid-1);
          }
       }


