/*  Customer implementation
 *  Name: Curtiss J Wiggins
 *  Project: Refactoring
 *  Course: cs33901
 */

#include "customer.h"
#include "movie.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

string Customer::statement()
{
  //double totalAmount          = 0;
  int    frequentRenterPoints = 0;

  // Init result string
  string result("Rental Record for ");
  result += getName();
  result += "\n";

  for (vector<Rental>::iterator it = _rentals.begin();
                                it != _rentals.end(); ++it)
  {
      Rental& aRental = *it;

	 // frequentRenterPoints += aRental.getFrequentRenterPoints();
        // Include in result
        result += "\t";
        result += aRental.getMovie().getTitle();
        result += "\t";

        // Convert int to a string.
        // Output the int object into the output string stream.
        std::ostringstream out_str_stream;
        out_str_stream << aRental.getCharge();
        result += out_str_stream.str();
        result += "\n";
    }
    result += "Amount owed is: ";

     // Convert int to a string.
     // Output the int object into the output string stream.
    std::ostringstream out_str_stream;
    out_str_stream << getTotalCharge();
    result += out_str_stream.str();
    result += "\n";
    result += "You earned: ";
    std::ostringstream out_str_stream2;
    out_str_stream2 << getTotalFrequentRenterPoints();
    result += out_str_stream2.str();
    result += " frequent renter points\n";

    return result;
}

double Customer::getTotalCharge() {
	double subTotal = 0;
	for(vector<Rental>::iterator it = _rentals.begin(); it != _rentals.end(); ++it)
	{
		Rental& aRental = *it;
		subTotal += aRental.getCharge();
	}
	return subTotal;
}

int Customer::getTotalFrequentRenterPoints() {
	int frequentRenterPoints = 0;
	for(vector<Rental>::iterator it = _rentals.begin(); it != _rentals.end(); ++it)
	{
		Rental& aRental = *it;
		frequentRenterPoints += aRental.getFrequentRenterPoints();
	}
	return frequentRenterPoints;
}
