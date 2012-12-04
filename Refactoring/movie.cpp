/*  Movie implementation
 *  Name: Curtiss J Wiggins
 *  Project: Refactoring
 *  Courses: cs33901
 */

#include "movie.h"


double Movie::getCharge(int daysRented) {
	return _price_code->getCharge(daysRented);
}

void Movie::setPriceCode(int price_code) {
	delete _price_code;
	switch( price_code ) {
		case REGULAR:
			_price_code = new RegularPrice;
			break;
		case CHILDRENS:
			_price_code = new ChildrensPrice;
			break;
		case NEW_RELEASE:
			_price_code = new NewReleasePrice;
			break;
	}
}

double RegularPrice::getCharge(int daysRented) const
{
	double thisAmount = 2;
	if(daysRented > 2)
		return (thisAmount += (daysRented - 2) * 1.5);
}

double NewReleasePrice::getCharge(int daysRented) const
{
	return daysRented * 3;
}

double ChildrensPrice::getCharge(int daysRented) const
{
	double thisAmount = 1.5;
	if (daysRented > 3)
		return (thisAmount += (daysRented - 3) * 1.5);
}

int NewReleasePrice::getFrequentRenterPoints(int daysRented) const
{
	return (daysRented > 1) ? 1 : 2;
}
