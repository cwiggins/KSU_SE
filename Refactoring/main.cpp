#include "movie.h"
#include "rental.h"
#include "customer.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;

int main()
{
  // Create some movie objects.
  Movie *lotr = new Movie("Lord of the Rings", Movie::REGULAR);
  Movie *hp   = new Movie("Harry Potter",      Movie::CHILDRENS);

  // Create a Rental and add the Movies to it.
  Rental r1(*lotr, 10);
  Rental r2(*hp, 5);

  // Create a customer and add the rental.
  Customer mike("Mike Smith");
  mike.addRental(r1);
  mike.addRental(r2);

  // Get the statement for the Customer.
  string statement = mike.statement();
  cout << statement;

  // Free the movies.
  delete lotr;
  delete hp;
}

