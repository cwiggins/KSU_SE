/*  Name: Curtiss J Wiggins
 *  Project: Refactoring
 *  Course: cs33901
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Price
{
	public:
		virtual ~Price() {};

		//Acessors
		virtual int getPriceCode() const = 0;
		virtual double getCharge(int) const = 0;
		virtual int getFrequentRenterPoints(int daysRented) const { return 1; };
};

class Movie
{
  public:
    // Define movie types
    enum movie_types { REGULAR, CHILDRENS, NEW_RELEASE };
    // Constructors
    Movie(std::string title, int price_code)
	   :  _title(title), _price_code(0)
	{
		setPriceCode(price_code);
	};



    // Accessors
    std::string  getTitle()     { return _title;      }
    int          getPriceCode() const { return _price_code->getPriceCode(); };

    // Mutators
    void setPriceCode(int price_code);

	double getCharge(int);
	int getFrequentRenterPoints(int daysRented) const { return _price_code->getFrequentRenterPoints(daysRented); };

  private:
    std::string _title;
    Price		*_price_code;

};

class RegularPrice : public Price
{
	public:
		virtual int getPriceCode() const { return Movie::REGULAR; };
		virtual double getCharge(int) const;
};

class NewReleasePrice : public Price
{
	public:
		virtual int getPriceCode() const { return Movie::NEW_RELEASE; };
		virtual double getCharge(int) const;
		virtual int getFrequentRenterPoints(int) const;
};

class ChildrensPrice : public Price
{
	public:
		virtual int getPriceCode() const { return Movie::CHILDRENS; };
		virtual double getCharge(int) const;
};
#endif
