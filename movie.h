#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
using namespace std;

class Movie: public Product{
  public:
  Movie (string genre, string rating, const std::string category, const std::string title, double price, int q);
  ~Movie();
  string parseGenre();
  string parseRating();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream &os) const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;


  private:
  string genre_;
  string rating_;
};

#endif