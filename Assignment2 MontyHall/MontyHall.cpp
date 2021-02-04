#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

/***** Complete this program. *****/

using namespace std;

//to assign new name(Door) to int data type
typedef int Door;


//Declaring following varibale as global to enable using them in main and other functions too.
const int SIMULATION_COUNT =100;
Door hide_car=0, first_choice=0, open_door=0, second_choice=0;
float first_win=0.0, second_win=0.0;


//randomly picking a door to hide the car out of three doors
//@return variable that contains car
Door hideCar(){
   hide_car=rand()%3+1;
   cout<< setw(8)<<hide_car;
   return hide_car;
}

//Acting as contenstant,I, randomly picking a door as my first door choice
//@return variable which contains door choosen by contenstant
Door makeFirstChoice(){
   first_choice=rand()%3+1;
   cout<<setw(8) <<first_choice;
      return first_choice;
}

/**
 * Acting as Monty,opening a door to reveal a goat.
 * Monty knows which door has car so he will not open that door.
 * Also, Monty can not choose the door which contenstant have already chosen.
 * @return opened
 */
Door openDoor(){
   do{
      open_door=rand()%3+1;
       }
 while(open_door==hide_car|| open_door==first_choice);
 cout<<setw(8)<< open_door;
        return open_door;
}


//As a contenstant, switching to the door which is left unopened.
//Making sure, not choosing the door which has already opened and chosen in first time
Door makeSecondChoice(){
  do{
      second_choice=rand()%3+1;
      }
   while(second_choice==open_door || second_choice==first_choice);
    cout<<setw(8)<< second_choice;
      return second_choice;
   }

//Calcualting winning numbers in both staying with first or switching to second choices
void simulate(){
      if (first_choice== hide_car){
      first_win+=1;
      cout<<setw(8)<<"yes"<<endl;
      }
      else if (second_choice==hide_car){
      second_win+=1;
      cout<<setw(16)<<"yes"<<endl;}
      }



int main()
{
    //seeding rand function with NULL pointer to get different values
    srand(time(NULL));
    int counter=1;

cout<<setw(8)<<"#"<<setw(8)<<"Car"<<setw(8)<<"First"<<setw(8)<<"Opened"<<setw(8)<<"Second"<<setw(8)<<"Win"<<setw(8)<<"Win"<<endl;
cout<<setw(8)<<" "<<setw(8)<<"here"<<setw(8)<<"choice"<<setw(8)<<"door"<<setw(8)<<"choice"<<setw(8)<<"first"<<setw(8)<<"second"<<endl<<endl;


 //Running a simulation in loop
 //Calling all the functions in main function to get respective values and print them
 for (int i = 1; i <= SIMULATION_COUNT; i++) {
     cout<<setw(8)<<counter;
     hideCar();
     makeFirstChoice();
     openDoor();
     makeSecondChoice();
     simulate();
     counter+=1;
   }
cout<<setw(8)<<first_win <<" wins if stay with the first choice"<<endl;
cout<<setw(8)<<second_win << " wins if switch with the second choice"<<endl;
cout << "Win ratio of switch over stay: "<< (second_win/first_win);
return 0;
}

