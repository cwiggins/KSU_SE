/*  Name: Curtiss j Wiggins
 *  Project: Refactoring
 *  Course: cs33901*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "rental.h"

#include <string>
#include <vector>

class Customer
{
  public:
    // Constructors
    Customer(std::string name)
      : _name(name)
    { }

    // Accessors
    std::string getName() { return _name; }

    // Mutators
    void addRental(Rental rental)
      { _rentals.push_back(rental); }

   // Other
   std::string statement();

  private:
    double getTotalCharge();
	int getTotalFrequentRenterPoints();
    std::string         _name;
    std::vector<Rental> _rentals;

};

#endif
