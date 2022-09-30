#include "book.h"
#include "product.h"
#include "util.h"
#include "clothing.h"
#include "util.cpp"
#include <set>
#include <string>
#include <iostream>

using namespace std;

Clothing::Clothing(string size, string brand, const string category, const string name, double price, int qty)
:Product(category,name,price,qty){
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing()
{}

string Clothing::parseSize()
{
  return size_;
}

string Clothing::parseBrand()
{
  return brand_;
}

string Clothing::displayString() const
{
  string strPrice = to_string(price_);
  string strQ = to_string(qty_);
  string display = "Size: " + size_ + " Brand:: " + brand_ + "\n" + strPrice + " " + strQ + " left.";
  return display;
}

void Clothing::dump(std::ostream &os) const
{
   os << size_ << " "  << brand_ << " " << category_ << " " << name_ << " " << price_ << " " << qty_ << endl;
}

set <string> Clothing::keywords() const
{
  set<string> parsedName = parseStringToWords(name_);
  set<string> parsedBrands = parseStringToWords(size_);
  set<string> clothingKeywords = setUnion (parsedName, parsedBrands);
  clothingKeywords.insert(brand_);
  return clothingKeywords;
}


