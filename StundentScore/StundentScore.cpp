/*
 * StundentScore.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";


typedef string   *NamePtr;   // -> a student name
typedef string   *NameArray; // -> dynamic array of student names
typedef int      *ScorePtr;  // -> a score
typedef int      *ScoreRow;  // -> dynamic array (row) of student scores
typedef ScoreRow *RowArray;  // -> dynamic array of pointers to score rows
typedef ScoreRow *RowPtr;    // -> a pointer to a score row


int main(){
	ifstream input;
	input.open(INPUT_FILE_NAME);

	if(input.fail()){

		cout <<"failed to open" << INPUT_FILE_NAME<<endl;
	}







}






