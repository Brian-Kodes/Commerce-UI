#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class Book:public Product{
  public:
  Book(std::string isbn, std::string author, const std::string category, const std::string name, double price, double qty);
  ~Book();
  std::string parseISBN();
  std::string parseAuthor();
  virtual std::string displayString() const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;
  virtual std::set<std::string> keywords() const;
  virtual void dump(std::ostream &os) const;

  private:
  std::string isbn_;
  std::string author_;
};

#endif