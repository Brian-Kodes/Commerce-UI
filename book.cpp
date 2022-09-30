#include "book.h"
#include "product.h"
#include "util.h"
#include "util.cpp"
#include <set>
#include <string>
#include <iostream>

using namespace std;

Book::Book(string isbn, string author, const string category, const string name, double price, int qty)
:Product(category,name,price,qty){
  isbn_ = isbn;
  author_ = author;
}
Book::~Book()
{}

string Book::parseISBN()
{
  return isbn_;
}

string Book::parseAuthor()
{
  return author_;
}

string Book::displayString() const
{
  string strPrice = to_string(price_);
  string strQ = to_string(qty_);
  string display = "Author: " + author_ + " ISBN: " + isbn_ + "\n" + strPrice + " " + strQ + " left.";
  return display;
}

void Book::dump(std::ostream &os) const
{
   os << isbn_ << " "  << author_ << " " << category_ << " " << name_ << " " << price_ << " " << qty_ << endl;
}

set <string> Book::keywords() const
{
  set<string> parsedName = parseStringToWords(name_);
  set<string> parsedAuthor = parseStringToWords(author_);
  set<string> bookKeywords = setUnion (parsedName, parsedAuthor);
  bookKeywords.insert(isbn_);
  return bookKeywords;
}


