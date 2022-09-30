#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
using namespace std;

class Clothing: public Product{
  public:
  Clothing (string size, string brand, const std::string category, const std::string name, double price, int q);
  ~Clothing();
  string parseSize();
  string parseBrand();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream &os) const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;


  private:
  string size_;
  string brand_;
};

#endif