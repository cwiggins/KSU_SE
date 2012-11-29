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
    std::string         _name;
    std::vector<Rental> _rentals;

};

#endif
