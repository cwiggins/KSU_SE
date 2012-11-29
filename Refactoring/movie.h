#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
  public:
    // Define movie types
    enum movie_types { REGULAR, NEW_RELEASE, CHILDRENS };

    // Constructors
    Movie(std::string title, int price_code)
      : _title(title), _price_code(price_code)
    { }

    // Accessors
    std::string  getTitle()     { return _title;      }
    int          getPriceCode() { return _price_code; }

    // Mutators
    void setPriceCode(int price_code)
        { _price_code = price_code; }
    
  private:
    std::string _title;
    int         _price_code;

};

#endif
