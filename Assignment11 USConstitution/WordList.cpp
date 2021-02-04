


#include <list>
#include "TimedContainer.h"
#include "Word.h"
#include <iterator>
#include "WordList.h"
#include <ctype.h>
#include<iostream>
#include<bits/stdc++.h>




    /**
     * Default constructor.
     */

    int  WordList::get_count(const string text){
    	list<word>::iterator it= search(text);
    	if(it!=end()){
    		return it->get_count();
    	}
    	return;
    }



    void WordList::insert(const string text) {
       steady_clock::time_point start = std::chrono::steady_clock::now();
       list<Word>::iterator it = search(text);
       if(it != end()) {
          it->increment_count();
          return;
       }

       string lower_text =text;
       transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
       Word word(lower_text);
       for(list<Word>::iterator it=begin(); it != end(); it++) {
          string list_text = it->get_text();
          if(list_text > lower_text) {
             list<Word>::insert(it, word);
             return;

          }
       }
       push_back(word);
       increment_elapsed_time(start, std::chrono::steady_clock::now());
    }


    list<Word>::iterator WordList::search(const string text) {
       steady_clock::time_point start = steady_clock::now();
       string lower_text = text;
       transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
       for(list<Word>::iterator it=begin(); it != end(); it++) {
          if(it->get_text() == lower_text) {
             increment_elapsed_time(start, steady_clock::now());
             return it;

          }
       }
       increment_elapsed_time(start, steady_clock::now());
       return end();
    }




