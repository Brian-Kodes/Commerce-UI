#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "util.h"
#include <map>

//searching, adding products and users, saving database, etc.
class myDataStore : public DataStore {
public:
  myDataStore();
  ~myDataStore();
  void addProduct(Product* p);
  void addUser (User* u);
  std::vector<Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);
  void buyCart (std::string username);
  std::vector <Product*> getCart (std::string username);
  void addtoCart (std::string username,Product *p);



private:
  std::map<std::string, User*> user_;
  std::map<std::string, std::set<Product*>> product_;
  std::map<std::string, std::vector<Product*>>userCart;
  std::set<Product*> productList;
  std::map<std::string, std::vector<Product*>>linkUserCart;


};

#endif