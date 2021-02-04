/***** Complete this file. *****/
#include "WordMap.h"
#include <ctype.h>

#include<iostream>

using namespace std;

    int WordMap::get_count(const string text)  {
       map<string, Word>::iterator it = search(text);
       if(it != end()) {
          return it->second.get_count();
       }
       return 0;
    }


    void WordMap::insert(const string text) {
       steady_clock::time_point start = std::chrono::steady_clock::now();
       map<string, Word>::iterator it = search(text);
       if(it != end()) {
          it->second.increment_count();
          return;
       }
       string lower_text = text;
      transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
       Word word(lower_text);
       map<string, Word>::insert({lower_text, word});
       increment_elapsed_time(start,
                                 std::chrono::steady_clock::now());
    }


    map<string, Word>::iterator WordMap::search(const string text) {
      string lower_text = text;
      transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
      steady_clock::time_point start = std::chrono::steady_clock::now();
      map<string, Word>::iterator it = map<string, Word>::find(lower_text);
      increment_elapsed_time(start,
                                 std::chrono::steady_clock::now());
      return it;
    }
