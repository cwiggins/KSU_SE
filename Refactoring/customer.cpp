/*  Customer implementation
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
  double totalAmount          = 0;
  int    frequentRenterPoints = 0;

  // Init result string
  string result("Rental Record for ");
  result += getName();
  result += "\n";

  for (vector<Rental>::iterator it = _rentals.begin();
                                it != _rentals.end(); ++it)
  {
      double thisAmount = 0;
      Rental& each = *it;
      switch(each.getMovie().getPriceCode())
      {
        case Movie::REGULAR:
                thisAmount += 2;
                if (each.getDaysRented() > 2)
                    thisAmount += (each.getDaysRented() - 2) * 1.5;
                break;
        case Movie::NEW_RELEASE:
                thisAmount += each.getDaysRented() * 3;
                break;
        case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (each.getDaysRented() > 3)
                    thisAmount += (each.getDaysRented() - 3) * 1.5;
                break;
      }
        // Add frequent renter's points
        ++frequentRenterPoints;

        // Add bonus for new release rental
        if ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE &&
             each.getDaysRented() > 1 )
            ++frequentRenterPoints;
       
        // Include in result
        result += "\t";
        result += each.getMovie().getTitle();
        result += "\t";

        // Convert int to a string.
        // Output the int object into the output string stream.
        std::ostringstream out_str_stream;
        out_str_stream << thisAmount;
        result += out_str_stream.str();
        result += "\n";
        totalAmount += thisAmount;
    }
    result += "Amount owed is: ";

     // Convert int to a string.
     // Output the int object into the output string stream.
    std::ostringstream out_str_stream;
    out_str_stream << totalAmount;
    result += out_str_stream.str();
    result += "\n";
    result += "You earned: ";
    std::ostringstream out_str_stream2;
    out_str_stream2 << frequentRenterPoints;
    result += out_str_stream2.str();
    result += " frequent renter points\n";

    return result;
}



