#ifndef BOOK_H
#define BOOK_H

#include "product.h"
using namespace std;

class Book:public Product{
  public:
  Book(string isbn, string author, const string category, const string name, double price, int qty);
  ~Book();
  string parseISBN();
  string parseAuthor();
  virtual std::string displayString() const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;
  virtual std::set<std::string> keywords() const;
  virtual void dump(std::ostream &os) const;

  private:
  string isbn_;
  string author_;
};

#endif