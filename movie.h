#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie: public Product{
  public:
  Movie (std::string genre, std::string rating, const std::string category, const std::string title, double price, int qty);
  ~Movie();
  std::string parseGenre();
  std::string parseRating();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream &os) const;
  virtual bool isMatch(std::vector<std::string>& searchTerms) const;


  private:
  std::string genre_;
  std::string rating_;
};

#endif