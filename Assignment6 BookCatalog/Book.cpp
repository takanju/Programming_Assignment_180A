#include "Book.h"
#include <string>
using namespace std;

using namespace std;

Book::Book() {
	ISBN = "";
	lastName = "";
	firstName = "";
	titleBook = "";
	categoryBook;
}

Book::Book(string isbn, string last, string first, string title,
		Category category) {
	ISBN = isbn;
	lastName = last;
	firstName = first;
	titleBook = title;
	categoryBook = category;
}

string Book::getIsbn() const{
	   return ISBN;

    }

   string Book::getLast() const{
	   return lastName;
   }

   string Book::getCategory() const{
	   string str = convertToString();
	   return str;
   }

bool Book::operator==(Book B) {

	return B.ISBN == ISBN;
}

bool Book::operator>(Book B) {

	return ISBN > B.ISBN;
}

bool Book::operator<(Book B) {

	return ISBN < B.ISBN;
}


bool Book::operator!= (Book B)
{
  if (ISBN!= B.ISBN)
    {
      return true;
    }
  return false;
}




istream &operator>>( istream  &input, Book &B ) {

return input;
      }

ostream& operator<<(ostream &output, const Book &B) {
	string str = "Book{ISBN=" + B.ISBN + ",last=" + B.lastName + ","
			+ " first=" + B.firstName + ",title=" + B.titleBook + ",category="
			+ B.convertToString();
	output << str;

	return output;

}

string Book::convertToString() const {

	if (categoryBook == Book::Category::FICTION) {
		return "fiction";

	}
	else if (categoryBook == Book::Category::HISTORY) {
		return "history";

	}
	else if (categoryBook == Book::Category::TECHNICAL) {
		return "technical";

	}
	return "";

}

Book::Category convertToEnum(string category) {
	if (category == "fiction") {
		return Book::Category::FICTION;

	}
	else if (category == "history") {
		return Book::Category::HISTORY;

	}
	else if (category == "technical") {
		return Book::Category::TECHNICAL;

	}
}

