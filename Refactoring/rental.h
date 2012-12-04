/*  Name: Curtiss J Wiggins
 *  Project: Refactoring
 *  Course: cs33901
 */
#ifndef RENTAL_H
#define RENTAL_H

#include "movie.h"

class Rental
{
  public:
    // Comstructors
    Rental(Movie movie, int days_rented)
      : _movie(movie), _days_rented(days_rented)
    { }

    // Accessors
    int   getDaysRented() { return _days_rented; }
    Movie getMovie()      { return _movie;       }

	double getCharge();
	int getFrequentRenterPoints();

    // Mutators

  private:
    Movie _movie;
    int   _days_rented;
};

#endif
