#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// Names to search for.
const string ALEXEEVICH  = "Makar Alexeevich";
const string BAZDEEV     = "Joseph Bazdeev";
const string DRUBETSKOY  = "Boris Drubetskoy";
const string INPUT_FILE_NAME = "WarAndPeace.txt";

//Reading file line by line until it reaches to end.
//@param linesInFile as a vector of type string, storing file's lines.
//@return linesInFile
vector<string> readStoreVector(string fileName);

//Spliting given names to search around spaces.
//@param words as a vector of type string, storing name in splitting way.
//@return words.
vector<string> getFirstAndLastName(string name);

//Checking if line in file ends with first name.
//@param line and suffix as constant string type, storing line of file and first name.
//@return bool value.
static bool endsWith(const string& line, const string& suffix);

//Checking if just the next of current line in file starts with last name.
//@param line and prefix as constant string type, storing line of file and last name.
//@return bool value.
static bool startsWith(const string& line, const string& prefix);

//Finding names in lines.
//Checking every given condition and finding names in line.
//Findind names in alphabatical order according to their last name.
//Checking endsWith and startsWith condition
void findFunction(vector<string> linesInFile);

int main()
{
    cout << " LINE  "<<left<< "POSITION" <<setw(8) << "    NAME"<<endl;
    vector<string> linesInFile = readStoreVector("WarAndPeace.txt");
    findFunction( linesInFile);
}

vector<string> readStoreVector(string fileName)
{
    ifstream input;
    input.open(INPUT_FILE_NAME);

    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
    }
   vector<string>  linesInFile;
   string line;

   //iterating til it reads end line.
    while (getline(input, line))
    {
       linesInFile.push_back(line);
   }
    return linesInFile;
}

vector<string> getFirstAndLastName(string name) {
    vector<string> words;
    istringstream ss(name);
 do {
        // Reading a word
        string word;
        ss >> word;
        words.push_back(word);

        // Checking condition if there is more to read
    } while (ss);
    return words;
}

static bool endsWith(const string& line, const string& suffix)
{
    return line.size() >= suffix.size() && 0 == line.compare(line.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(const string& line, const string& prefix)
{
    return line.size() >= prefix.size() && 0 == line.compare(0, prefix.size(), prefix);
}

void findFunction(vector<string>  linesInFile){
   vector<string> names ={ALEXEEVICH, BAZDEEV,DRUBETSKOY};
     unsigned int i=0;

   while( i<  linesInFile.size()){
       string lines =  linesInFile.at(i);
       for(unsigned int j=0; j<names.size(); j++){

          //finding names in lines according to alphabatical order
       size_t found = lines.find(names[j]);

       //finding name until the end to the line
       if(found != string::npos ){
          cout << i + 1<<setw(10)<<right << found + 1 << "     " <<names[j] << endl;
              }
       vector<string> splited = getFirstAndLastName(names[j]);
       string lastName = splited[1];
       string firstName = splited[0];
       bool firstNameFound = endsWith(lines, firstName);
       if(firstNameFound && i + 1 <  linesInFile.size())
       {
          bool lastNameFound = startsWith( linesInFile.at(i+1), lastName);
          if(lastNameFound)
          {
            cout << i + 1 <<setw(10)<< right<<lines.length() - firstName.length() + 1<<"    " << names[j]<<endl;
          }
       }
       }
      i++;
    }
}



