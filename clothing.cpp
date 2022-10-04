#include "product.h"
#include "clothing.h"
#include "util.h"
#include <set>
#include <string>
#include <iostream>


Clothing::Clothing(std::string size, std::string brand, const std::string category, const std::string name, double price, int qty)
:Product(category,name,price,qty){
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing()
{}

std::string Clothing::parseSize()
{
  return size_;
}

std::string Clothing::parseBrand()
{
  return brand_;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Clothing::displayString() const
{
  std::string strPrice = std::to_string(price_);
  std::string strQ = std::to_string(qty_);
  std::string display = "Size: " + size_ + " Brand:: " + brand_ + "\n" + strPrice + " " + strQ + " left.";
  return display;
}

void Clothing::dump(std::ostream &os) const
{
   os << size_ << " "  << brand_ << " " << category_ << " " << name_ << " " << price_ << " " << qty_ << std::endl;
}

std::set <std::string> Clothing::keywords() const
{
  std::set<std::string> parsedName = parseStringToWords(name_);
  std::set<std::string> parsedBrands = parseStringToWords(size_);
  std::set<std::string> clothingKeywords = setUnion (parsedName, parsedBrands);
  clothingKeywords.insert(brand_);
  return clothingKeywords;
}


