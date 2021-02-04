#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book {
public:
	/**
	 * Book categories.
	 */
	enum class Category {
		FICTION, HISTORY, TECHNICAL, NONE
	};

	/**
	 * Default constructor.
	 */
	Book();

	/**
	 * Constructor.
	 */
	Book(string isbn, string last, string first, string title,
			Category category);

	/**
	 * Destructor.
	 */
	//~Book();

	/**
		 * @return ISBN;
		 */
	string getIsbn() const;

	/**
	 * @return Last Name;
	 */
   string getLast() const;

   /**
   	 * @return category book;
   	 */
	string getCategory() const;


	 /**
	   	 * @return string, the converted enum category to string
	   	 */
	string convertToString() const;

	 /**
	   * Overloaded operator for equality.
	   * @param B the other book object to compare to.
	   * @return true if they're equal
	   */
    bool operator==(Book B);


    /**
     * Overloaded operator to comapre.
     * @param B the other book object to compare to.
     * @return true if they're equal
     */
	bool operator>(Book B);

	 /**
	   * Overloaded operator to comapre.
	   * @param B the other book object to compare to.
       * @return true if they're equal
       */
	bool operator<(Book B);


	bool operator!= (Book B);

	/**
	  * Overloaded operator to write a Book in the given ouput form
      * @param output the output stream.
      * @param B, object of the book
      * @return the output stream.
      */
	friend ostream& operator<<(ostream &output, const Book &B);
	friend istream &operator>>( istream  &input, Book &B );

private:

	string ISBN;
	string lastName;
	string firstName;
	string titleBook;
	Category categoryBook;

};

#endif /* EMPLOYEE_H_ */
