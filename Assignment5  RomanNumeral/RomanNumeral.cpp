#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "RomanNumeral.h"
using namespace std;


/* store key value, map value  of data type char, int respectively */
/* Declare globally */
map < char, int >mapOfRomanNumbers = {
  {
   'I', 1},
  {
   'V', 5},
  {
   'X', 10},
  {
   'L', 50},
  {
   'C', 100},
  {
   'D', 500},
  {
   'M', 1000}
};



/* store key value, map value  of data type int, string respectively */
/* Declare globally */
map < int, string > mapOfDecimalNumbers = {
  {
   1, "I"},
  {
   4, "IV"},
  {
   5, "V"},
  {
   9, "IX"},
  {
   10, "X"},
  {
   40, "XL"},
  {
   50, "L"},
  {
   90, "XC"},
  {
   100, "C"},
  {
   400, "CD"},
  {
   500, "D"},
  {
   900, "CM"},
  {
   1000, "M"}
};


// initialization of member variables
RomanNumeral:: RomanNumeral() {
    roman="";
    decimal =0;

 }

// set values to member variables when constructor takes string
 RomanNumeral::RomanNumeral(string rom){
    roman=rom;
    decimal=to_decimal(roman);
    }

// set values to member variables when constructor takes int
  RomanNumeral::RomanNumeral(int dec){
    decimal=dec;
    roman=to_roman(dec);
    }

string RomanNumeral::to_roman(int &dec)
{

    string rom = "";
    int q = 0, r = 0;
    if (dec >= 1000 && dec <= 3999) {
        q = dec / 1000;                //get first digit of dec
        r = dec % 1000;                //get last three digits of dec
        dec=r;                         //assigning last three digits to dec to continue with other conditions
        for (int i = 0; i < q; i++) {
            rom += mapOfDecimalNumbers[1000];     //get map value of 1000
        }
    }
    if (dec >= 900 && dec <= 999) {
        q = dec / 900;
        r = dec % 900;
        dec = r;
        rom += mapOfDecimalNumbers[900];
    }
    if (dec >= 500 && dec <= 899) {
        r = dec % 500;
        dec = r;
        rom += mapOfDecimalNumbers[500];
    }
    if (dec >= 400 && dec <= 499) {
        r = dec % 100;
        dec = r;
        rom += mapOfDecimalNumbers[400];
    }
    if (dec >= 100 && dec <= 399) {
        q = dec / 100;
        r = dec % 100;
        dec = r;
        for (int i = 0; i < q; i++) {
            rom += mapOfDecimalNumbers[100];
        }
    }

    if (dec >= 50 && dec <= 99) {
        r = dec % 50;
        dec = r;
        rom += mapOfDecimalNumbers[50];
    }

    if (dec >= 40 && dec <= 49) {
        r = dec % 10;
        dec = r;
        rom += mapOfDecimalNumbers[40];
    }
    if (dec >= 10 && dec <= 39) {
        q = dec / 10;
        r = dec % 10;
        dec = r;
        for (int i = 0; i < q; i++) {
            rom += mapOfDecimalNumbers[10];
        }
    }
    if (dec == 9) {
        rom += mapOfDecimalNumbers[9];
        dec = 0;
    }
    if (dec >= 5 && dec <= 8) {
        r = dec % 5;
        dec = r;
        rom += mapOfDecimalNumbers[5];
    }
    if (dec == 4) {
        rom += mapOfDecimalNumbers[4];
    }
    if (dec >= 1 && dec <= 3) {
        q = dec/1;
        r = dec % 1;
        dec = r;
        for (int i = 0; i < q; i++) {
            rom += mapOfDecimalNumbers[1];
        }
    }

    return rom;
}




int RomanNumeral::to_decimal(string &rom)
{
  int number = 0;
  string r = rom;
  unsigned int i = 0;

  while (i < rom.length())
    {
       //iterate if string is of more than 1 character
      //compare two consecutive characters
      //add characters if previous one is greater
      while (i + 1 < rom.length()
	     && mapOfRomanNumbers.find(rom[i])->second >= mapOfRomanNumbers.find(rom[i + 1])->second)
	{
	  number +=
	    mapOfRomanNumbers.find(rom[i])->second;
	  i++;
	}

      while (i + 1 < rom.length()
	     && mapOfRomanNumbers.find(rom[i])->second <
	     mapOfRomanNumbers.find(rom[i + 1])->second)
	{
	  number -=
	    mapOfRomanNumbers.find(rom[i])->second;
	  i++;
	}
      if (i == rom.length()-1)
	{
	  number += mapOfRomanNumbers.find(rom[i])->second;
	  i++;

	}
    }
  return number;
}


int RomanNumeral:: getD() const
{
     return decimal;
}

string RomanNumeral:: getS() const
{
    return roman;
 }


RomanNumeral RomanNumeral::operator+ (RomanNumeral rn)
{
  RomanNumeral temp(decimal + rn.decimal);
  return temp;
}



RomanNumeral RomanNumeral::operator- (RomanNumeral rn)
{
  RomanNumeral temp(decimal-rn.decimal);
  return temp;
}


RomanNumeral RomanNumeral::operator* (RomanNumeral rn)
{
  RomanNumeral temp(decimal * rn.decimal);
  return temp;
}


RomanNumeral RomanNumeral::operator/ (RomanNumeral rn)
{
RomanNumeral temp(decimal / rn.decimal);
  return temp.decimal;
}


bool RomanNumeral::operator== (RomanNumeral rn)
{
  if (decimal == rn.decimal)
    {
      return true;
    }
  return false;
}



bool RomanNumeral::operator!= (RomanNumeral rn)
{
  if (decimal != rn.decimal)
    {
      return true;
    }
  return false;
}


//global declaration
istream &operator >> (istream &in,  RomanNumeral &rn)
{
   in >> rn.roman;
    rn.decimal = rn.to_decimal(rn.roman);
    return in;
}


//global declaration
ostream &operator << (ostream &out, const RomanNumeral &rn)
{
    out << "[" << rn.decimal << ":" << rn.roman << "]";
    return out;
}



