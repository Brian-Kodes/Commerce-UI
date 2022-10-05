#include "mydatastore.h"
#include <map>
#include <vector>
#include <utility>
#include <iostream>


using namespace std;
myDataStore::myDataStore()
{

}

myDataStore::~myDataStore()
{
  
}

void myDataStore::addProduct(Product* p)
{
  set<string> theseKeywords = p -> keywords();
  set<string>::iterator it;
  for (it = theseKeywords.begin(); it != theseKeywords.end(); it++)
  {
    if (product_.find(*it) != product_.end())
    {
      product_.find(*it)->second.insert(p);
    }
    else
    {
      set<Product*> newProducts;
      newProducts.insert(p);
      product_.insert(make_pair(*it, newProducts));
    }
  }
}

void myDataStore::addUser (User* u)
{
  vector<Product*> emptyCart;
  user_.insert(make_pair(u -> getName(), u));
  userCart.insert(make_pair(u -> getName(), emptyCart));
  
}

void myDataStore::buyCart (std::string username)
{ 
  User* thisUser = user_.find(username) -> second;
  std::vector<Product*> myCart;
  std::vector<Product*>::iterator it;
  std::vector<Product*> tempCart;
  if (user_.find(username) != user_.end()) // if user exists
  {
    if (userCart.find(username) == userCart.end())
    {
      cout << "cart doesn't exist" << endl;
    }
    myCart = userCart.find(username) -> second;
    for (unsigned int i = 0; i < myCart.size(); i++)
    {
      if (myCart[i] -> getPrice() <= thisUser -> getBalance())
      {
        myCart[i] -> subtractQty(1);
        thisUser -> deductAmount(myCart[i] -> getPrice());

      }
      else if (myCart[i] -> getPrice() > thisUser -> getBalance())
      {
        tempCart.push_back(myCart[i]);
      }
    }
    if (tempCart.size() > 0)
    {
      userCart.find(username) -> second = tempCart;

    }
    else //if user bought everything
    {
      userCart.erase(username);
    }

  }
}

std::vector<Product*> myDataStore::getCart (std::string username) // given string
{
  std::map<std::string, User*>::iterator it;
  std::vector<Product*> it22;
  std::map<std::string, std::vector<Product*>>::iterator it2;

    if (user_.find(username) != user_.end()) //user exisys
    {
      return userCart.find(username) -> second;

    }
    return it22;
}

std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, int type)
{
  std::set <Product*> setProd1;
  std::set <Product*> setProd2;
  std::set <Product*> finalSet;
  std::vector<Product*> cartMatch;
  std::vector<Product*> finalV;
  std::vector <Product*> unionV;
  std::vector <Product*> intersectionV;
  std::vector<std::string>::iterator it;
  std::set <Product*>:: iterator it2;
  bool isthisFirstIndex = true;
  bool isthisFirstIndexI = true;
  if (type == 1)//ORSEARCHUNION 
  {
    for (it = terms.begin(); it != terms.end(); ++it) // loop through each term
    {
      if (product_.find(*it) != product_.end()) //if this product has that name
      {
        if (isthisFirstIndex == true)
        {
          setProd1 = product_.find(*it)->second; // will give me a set
          isthisFirstIndex = false; 
        }
        else
        {
          setProd2 = product_.find(*it) -> second;
          setProd1 = setUnion(setProd1, setProd2);
        }
      } 
    }
    for (it2 = setProd1.begin(); it2 != setProd1.end(); ++it2)
    {
      finalV.push_back(*it2);
    }
  }
  else if (type == 0)//ANDSEARCHINTERSECTION
  {
    for (it = terms.begin(); it != terms.end(); ++it)
    {
      if (product_.find(*it) != product_.end())
      {
        if (isthisFirstIndexI == true)
        {
          setProd1 = product_.find(*it) -> second; // will give me a set
          isthisFirstIndexI = false;
        }
        else
        {
          setProd2 = product_.find(*it) -> second;
          setProd1 = setIntersection(setProd1, setProd2);
        }
      }
    }
    for (it2 = setProd1.begin(); it2 != setProd1.end(); ++it2)
    {
      finalV.push_back(*it2);
    }
  }
return finalV;
}

void myDataStore:: addtoCart(std::string username, Product* p)
{
  if (user_.find(username) != user_.end())
  {
    if (userCart.find(username) != userCart.end()) // he has a cart
    {
      (userCart.find(username)->second).push_back(p); 
    }
    else
    {
      std::vector<Product*> thisaddedCart;
      thisaddedCart.push_back(p);
      userCart.insert(std::pair<std::string, std::vector<Product*>>(username, thisaddedCart));
    }
  }
}

void myDataStore:: dump(std::ostream& ofile)
{
  std::map<std::string, std::set <Product*>>::iterator it;
  std::vector<Product*>::iterator it2;
  std::set<Product*> setofProducts;
  std::map<std::string, User*>::iterator it3;
  std::vector<Product*> vectorofProducts;
  ofile << "<Products>" << endl;
  //int sizeofSet = 0;
  for (it = product_.begin() ; it != product_.end(); it++)
  {
    vectorofProducts.assign((it -> second).begin(), (it->second).end());
    for (it2 = vectorofProducts.begin(); it2 != vectorofProducts.end(); it2++)
    {
      (*it2) -> dump(ofile);
    }

  }
  ofile << "/Product" << endl;
  ofile << "<users>" << endl;
  for (it3 = user_.begin(); it3 != user_.end(); it3++)
  {
    it3 -> second -> dump(ofile);
  }
}

