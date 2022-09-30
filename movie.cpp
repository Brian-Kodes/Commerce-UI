#include "book.h"
#include "product.h"
#include "movie.h"
#include "util.cpp"
#include <set>
#include <string>
#include <iostream>

using namespace std;

Movie::Movie(string genre, string rating, const string category, const string name, double price, int qty)
:Product(category,name,price,qty){
  genre_ = genre;
  rating_ = rating;
}
Movie::~Movie()
{}

string Movie::parseGenre()
{
  return genre_;
}

string Movie::parseRating()
{
  return rating_;
}

string Movie::displayString() const
{
  string strPrice = to_string(price_);
  string strQ = to_string(qty_);
  string display = "Genre: " + genre_ + " Rating: " + rating_ + "\n" + strPrice + " " + strQ + " left.";
  return display;
}

void Movie::dump(std::ostream &os) const
{
   os << genre_ << " "  << rating_ << " " << category_ << " " << name_ << " " << price_ << " " << qty_ << endl;
}

set <string> Movie::keywords() const
{
  set<string> parsedName = parseStringToWords(name_);
  set<string> parsedGenre = parseStringToWords(genre_);
  set<string> movieKeywords = setUnion (parsedName, parsedGenre);
  movieKeywords.insert(rating_);
  return movieKeywords;
}
