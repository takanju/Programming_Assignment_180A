#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";


//Reading file line by line.
//Creating 1D string dynamic array to store the student names.
//Creating 2D integer dynamic array to store the student score.
void readingLines(string fileName, int &rowsCount,int*** studentrecord, string **rows);

//Printing the output from the content of created arrays
void printstudentFileTable(int **studentRecord, string *rows, int rowsCount);

int main()
{

 ifstream input;
 input.open(INPUT_FILE_NAME);
 if (input.fail())

{
   cout << "Failed to open " << INPUT_FILE_NAME << endl;
   return -1;
}

cout<< "STUDENT SCORES for C++"<< endl << endl;
int** studentRecord = nullptr;
string* rows = nullptr;
int rowsCount=0;

readingLines(INPUT_FILE_NAME, rowsCount, &studentRecord, &rows);

printstudentFileTable(studentRecord, rows,rowsCount);

delete[] studentRecord;
delete[] rows;

return 0;
}



void readingLines(const string fileName, int &rowTotal, int ***studentScore, string** names){

  ifstream in;
  in.open(fileName);
  string line;
  string numberOfRows="0";
  int lineNum = 0;

  //traversing the loop until lines are being read
  while(getline(in,line)){
    if(lineNum == 0) {

       //finding first space.
      size_t found = line.find(" ");

      //finding space until the end of line
      if(found!=string::npos){

        string numbers=line.substr(found+1);

        //converting string to int data type
        rowTotal = atoi(numbers.c_str());

        //creating a 2D dynamic array of size given in first line to store scores
        *studentScore = new int*[rowTotal];

        //creating 1D dynamic array to store names.
        (*names) = new string[rowTotal];

      }
    }

    //checking all the conditions for space as per array values
    else {

       //To calculate number of spaces.
      int counter = 0;
      string first_and_last_name = " ";
      while(1) {
        size_t found = line.find(" ");
        if(found==string::npos) {
          found = line.length();
        }
        counter++;
        if(counter ==1 ) {
          first_and_last_name = line.substr(0, found) + " ";
        }
        if(counter == 2) {
          first_and_last_name += line.substr(0, found);
          (*names)[lineNum-1] = first_and_last_name;
        }

        if(counter == 3) {
          int numScores = atoi(line.substr(0, found).c_str());

          (*studentScore)[lineNum-1] = new int[numScores+1];
        }

        if(counter > 3) {
          (*studentScore)[lineNum-1][counter-4] = atoi(line.substr(0, found).c_str());
        }

           if(found == line.length()) {
          (*studentScore)[lineNum-1][counter-3] = '\0';
          break;
        }
        line = line.substr(found+1);

      }
    }
    lineNum++;
  }

}

void  printstudentFileTable(int **studentScores, string *names, int rowTotal){

  for(int i = 0; i < rowTotal; i++) {
    cout << names[i] << endl;
    int j = 0;

    //printing all values till end of string.
    while(studentScores[i][j] != '\0') {
      cout << setw(4)<< studentScores[i][j] << " ";
      j++;
    }
     if(j==0){
          cout<< setw(4)<<"   (none)";
       }
    cout << endl;
    cout<<endl;

  }

}
