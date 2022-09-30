#include "book.h"
#include "product.h"
#include "util.h"
#include "util.cpp"
#include <set>
#include <string>
#include <iostream>


Book::Book(std::string isbn, std::string author, const std::string category, const std::string name, double price, int qty)
:Product(category,name,price,qty){
  isbn_ = isbn;
  author_ = author;
}
Book::~Book()
{}

std::string Book::parseISBN()
{
  return isbn_;
}

std::string Book::parseAuthor()
{
  return author_;
}

std::string Book::displayString() const
{
  std::string strPrice = std::to_string(price_);
  std::string strQ = std::to_string(qty_);
  std::string display = "Author: " + author_ + " ISBN: " + isbn_ + "\n" + strPrice + " " + strQ + " left.";
  return display;
}

void Book::dump(std::ostream &os) const
{
   os << isbn_ << " "  << author_ << " " << category_ << " " << name_ << " " << price_ << " " << qty_ << std::endl;
}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> parsedName = parseStringToWords(name_);
  std::set<std::string> parsedAuthor = parseStringToWords(author_);
  std::set<std::string> bookKeywords = setUnion (parsedName, parsedAuthor);
  bookKeywords.insert(isbn_);
  return bookKeywords;
}


