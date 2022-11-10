#include "book.h"
#include "product.h"
#include <set>
#include "util.h"
#include <string>
#include <iostream>
#include <iomanip>


Book::Book(std::string isbn, std::string author, const std::string category, const std::string name, double price, double qty)
:Product(category,name,price,qty){
  isbn_ = isbn;
  author_ = author;
}
Book::~Book()
{}



std::string Book::displayString() const
{
  std::string strPrice = std::to_string(price_);
  std::string strfixedPrice = strPrice.substr(0,5);
  std::string strQ = std::to_string(qty_);
  //std::string strfixedQ = strQ.substr(0,5);
  std::string display = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + strfixedPrice + " " + strQ + " left.";
  return display;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Book::dump(std::ostream &os) const
{
   os << category_ << std::endl  << name_ << std::endl << std::setprecision(2) << std::fixed << price_ << std::endl << qty_ << std::endl << isbn_ << std::endl << author_ << std::endl;
}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> parsedName = parseStringToWords(name_);
  std::set<std::string> parsedAuthor = parseStringToWords(author_);
  std::set<std::string> bookKeywords = setUnion (parsedName, parsedAuthor);
  bookKeywords.insert(isbn_);
  return bookKeywords;
}


