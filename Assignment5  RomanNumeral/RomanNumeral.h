#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
#include <ostream>
#include <istream>
using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();

    /**
     *  constructor takes a string parameter.
     */
    RomanNumeral(string rom);


    /**
     *  constructor takes a int parameter.
     */
    RomanNumeral(int dec);

    /**
     *  @return RomanNumeral object's decimal value.
     */
   int getD() const;

   /**
     *  @return RomanNumeral object's string value.
     */
   string getS() const;

   /**
     *  enable direct addition operation with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    RomanNumeral operator+(RomanNumeral rn);

    /**
     *  enable direct subtraction operation with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    RomanNumeral operator-(RomanNumeral rn);

    /**
     *  enable direct multiplication operation with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    RomanNumeral operator*(RomanNumeral rn);

    /**
     *  enable direct devide operation with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    RomanNumeral operator/(RomanNumeral rn);

    /**
     *  enable direct devide comparisons with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    bool operator==(RomanNumeral rn);

    /**
     *  enable direct devide comparisons with Roman numerals
     *  @param object of RomanNumeral
     *  @return object of RomanNumeral
     */
    bool operator!=(RomanNumeral rn);


    /**
     *  Make friend because declaring globally in cpp file
     *  enable direct extraction with Roman numerals
     *  @param object of istream and RomanNumeral
     *  input  a roman numeral value as a string
     */
friend istream &operator >> (istream &in,  RomanNumeral &rn);

    /**
     *  Make friend because declaring globally in cpp file
     *  enable direct insertion with Roman numerals
     *  @param object of ostream and RomanNumeral
     *  output  a roman numeral value in the given form
     */
friend ostream &operator << (ostream &out, const RomanNumeral &rn);


private:
string roman;      //store roman numeral string
int decimal;        //store corresponding decimal value of abovd roman string



/**
     *  convert string roman numeral to decimal value
     *  @param rom variable of string
     *  @return int
     *  set value of member variable roman
 */
int to_decimal(string &rom);

/**
     *  convert int decimal value to string roman numeral
     *  @param dec variable of int
     *  @return string
     *  set value of member variable decimal
 */
string to_roman(int &dec);
};

#endif /* ROMANNUMERAL_H_ */
