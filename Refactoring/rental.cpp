/*  Rental implementation
 *  Name: Curtiss J Wiggins
 *  Project: Refactoring
 *  Course: cs33901
 */

#include "rental.h"

double Rental::getCharge() {

	return _movie.getCharge(this->getDaysRented());
}

int Rental::getFrequentRenterPoints() {
    return _movie.getFrequentRenterPoints(this->getDaysRented());
}
