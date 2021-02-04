/*

 * BookCatalog.cpp

 *

 *  Created on: Oct 4, 2020

 *      Author: swapnanjali

 */

#include "Book.h"

#include <fstream>

#include<iostream>

#include <vector>

#include <string>

#include <sstream>

using namespace std;

const string INPUT_FILE_NAME = "Book.txt";

/**

 * Split line by comma

 * @param line, the string of every single line in book

 * @return vector of string having extracted words, splitted by coma in line

 */

vector<string> splitComma(string line);

/**

 * convert string category to respective enum value

 * @param category, the string of category

 * @return enum of category

 */

Book::Category convertToEnum(string category);

/**

 * push objects in catalog vector in sorted ISBN.

 * @param catalog the vector of book catalog.

 * @param bookObject the object to book class.

 */

void pushinVector(vector<Book> &catalog, Book bookObject);

// Status codes.

enum class StatusCode {

	OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND

};

//@param s, object to class status code

//@return string value of corresponding status code(enum);

string convertStatusToString(StatusCode s);

/**

 * Find the book in the catalog with the given ISBN.

 * Use a binary search.

 * @param isbn the ISBN.

 * @param catalog the vector of book catalog.

 * @return the vector index of the book if found, else return -1.

 */

int find(const string isbn, const vector<Book> &catalog);

/**

 * The main. Open the command input file and loop to process commands.

 */

int main() {

	// Open the input file.

	ifstream input;

	input.open(INPUT_FILE_NAME);

	if (input.fail()) {

		cout << "Failed to open " << INPUT_FILE_NAME << endl;

		return -1;

	}

	vector<Book> catalog;     //create catalog vector

	catalog.reserve(100);     //reserve space to catalog

	string line;

	char command;

	string isbn, last, title, category, categoryB;

	int i = 0;
	int count = 0;

	while (getline(input, line)) {

		if (line[0] == '+') {

			vector<string> comma = splitComma(line.substr(2));

			Book::Category category = convertToEnum(comma[4]);

			Book bookObject(comma[0], comma[1], comma[2], comma[3], category);

			pushinVector(catalog, bookObject);

			cout << endl;

		}

		if (line == "?") {

			cout << "? All books in the catalog:" << endl;

			for (int i = 0; i < catalog.size(); i++) {

				cout << catalog[i] << endl;

			}

			cout << endl;

		}

		else if (line[0] == '?' && line.substr(2, 6) == "author") {

			last = line.substr(9);

			cout << endl << "? Book by author" << " " << last << ":" << endl;

			for (int i = 0; i < catalog.size(); i++) {

				if (catalog[i].getLast() == last) {

					cout << catalog[i] << endl;

				}

			}

			cout << endl;

		}

		else if (line[0] == '?' && line.substr(2, 8) == "category") {

			categoryB = line.substr(11);

			cout << "? Book in category " << " " << categoryB << ":"

			<< endl;

			for (int i = 0; i < catalog.size(); i++) {

				if (catalog[i].getCategory() == categoryB) {

					cout << catalog[i] << endl;

				}

			}

			cout << endl;

		}

		else if (line[0] == '$') {

			cout << endl << "$ "
					<< convertStatusToString(StatusCode::INVALID_COMMAND)
					<< endl << endl;

		}

		else if (line[0] == '?' && line.substr(2, 4) == "isbn") {

			string isbn = line.substr(7);

			cout << "? Book with ISBN " << isbn << ":" << endl;

			int mid = find(isbn, catalog);
			if (mid > 0) {
				cout << catalog[mid] << endl;
			}

			cout << "" << endl;

		}

//		else if(line[0]=='-'){
//
//			string isbn = line.substr(2);
//			int mid = find(isbn, catalog);
//			if(mid == -1){
//				cout<<"Removed  "<< catalog[mid]<<endl;
//				cout<< convertStatusToString(StatusCode::NOT_FOUND);
//		cout<<endl;
//
//			}
//			catalog.erase(catalog.begin() + mid);
//			cout<<endl;
//			cout<<"Removed " << catalog[mid]<<endl;
//
//
//			//cout<<isbn<< catalog[mid]<<endl;
//			//cout << endl<< "$ " << convertStatusToString(StatusCode::NOT_FOUND)<< endl<<endl;
//
//		}

		else if (line[0] == '-') {
			string isbn = line.substr(2);
			int flag = 0;

			for (int i = 0; i < catalog.size(); i++) {
				if (catalog[i].getIsbn() == isbn) {
					flag = 1;
					cout << "- Removed  ";

					cout << catalog[i] << endl;
					catalog.erase(catalog.begin() + i);
					break;

				}
			}
			if(flag==0){
				cout<<endl;
				cout<<"- Removed "<< "Book{ISBN="<<isbn<<", last=, first=, title=, category=none}" << endl;
				cout<< convertStatusToString(StatusCode::NOT_FOUND)<<endl;
			}


		}


		cout<<endl;
	}

}

vector<string> splitComma(string line) {

	stringstream ss(line);

	string token;

	vector<string> tokens;

	while (getline(ss, token, ',')) {

		tokens.push_back(token);

	}

	return tokens;

}

void pushinVector(vector<Book> &catalog, Book bookObject) {

	if (catalog.size() == 0) {

		catalog.push_back(bookObject);

		cout << "+ Inserted at index 0" << ": " << bookObject << endl << endl;

		return;

	}

	for (int i = 0; i < catalog.size(); i++) {

		if (catalog[i] == bookObject) {

			cout << endl;

			cout << "+ Inserted at index " << i << ":  " << bookObject << endl;

			cout << convertStatusToString(StatusCode::DUPLICATE) << endl;

			return;

		} else if (catalog[i] > bookObject) {

			auto itPos = catalog.begin() + i;

			catalog.insert(itPos, bookObject);

			cout << "+ Inserted at index " << i << ":  " << bookObject << endl;

			return;

		}

	}

	cout << "+ Inserted at index " << catalog.size() << ": " << bookObject

	<< endl;

	catalog.push_back(bookObject);

}

int find(const string isbn, const vector<Book> &catalog) {

	int low = 0, high = catalog.size() - 1;

	while (low <= high) {

		int mid = (low + high) / 2;

		if (isbn == catalog[mid].getIsbn()) {

			return mid;

		}

		if (isbn < catalog[mid].getIsbn()) {

			high = mid - 1;

		} else {

			low = mid + 1;

		}

	}

	return -1;

}

string convertStatusToString(StatusCode s) {

	if (s == StatusCode::DUPLICATE) {

		return "*** Duplicate ISDN ***";

	} else if (s == StatusCode::NOT_FOUND) {

		return "*** Book not found ***";

	} else if (s == StatusCode::INVALID_COMMAND) {

		return "*** Invalid Command ***";

	}

	return "";

}
