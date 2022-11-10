#include "movie.h"
#include "util.h"
#include <set>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
Movie::Movie(std::string genre, std::string rating, const std::string category, const std::string name, double price, double qty)
:Product(category,name,price,qty){
  genre_ = genre;
  rating_ = rating;
}
Movie::~Movie()
{}

std::string Movie::parseGenre()
{
  return genre_;
}

std::string Movie::parseRating()
{
  return rating_;
}

std::string Movie::displayString() const
{
  std::string strPrice = to_string(price_);
  std::string strfixedPrice = strPrice.substr(0,5);
  std::string strQ = to_string(qty_);
  //std::string strfixedQ = strQ.substr(0,5);
  std::string display = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + strfixedPrice + " " + strQ + " left.";
  return display;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Movie::dump(std::ostream &os) const
{
   os << category_ << std::endl  << name_ << std::endl << std::setprecision(2) << std::fixed << price_ << std::endl << qty_ << std::endl << genre_ << std::endl << rating_ << std::endl;
}

set <std::string> Movie::keywords() const
{
  set<string> parsedName = parseStringToWords(name_);
  set<string> parsedGenre = parseStringToWords(genre_);
  set<string> movieKeywords = setUnion (parsedName, parsedGenre);
  movieKeywords.insert(rating_);
  return movieKeywords;
}
