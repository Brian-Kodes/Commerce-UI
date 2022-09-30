#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

class Clothing: public Product{
  public:
  Clothing (std::string size, std::string brand, const std::string category, const std::string name, double price, int q);
  ~Clothing();
  std::string parseSize();
  std::string parseBrand();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream &os) const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;


  private:
  std::string size_;
  std::string brand_;
};

#endif