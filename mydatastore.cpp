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
  //int keyWordssize = theseKeywords.size();
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
  userCart.insert(make_pair(u, emptyCart));
  
}

void myDataStore::buyCart (std::string username)
{ // check if he ahs a cart
  User* thisUser = new User();
  std::vector<Product*> myCart;
  std::vector<Product*>::iterator it;
  std::vector<Product*> tempCart;
  thisUser = (user_.find(username) -> second);
  //double sumofPrices = 0;
  if (user_.find(username) != user_.end())
  {
    myCart = userCart.find(user_.find(username) -> second) -> second;
    //for (it = myCart.begin(); it != myCart.end(); it++)
    for (unsigned int i = 0; i < myCart.size(); i++)
    {
      //if (//money quantity))
      if (myCart.at(i) -> getPrice() < thisUser -> getBalance())
      {
        myCart.at(i) -> subtractQty(1);
        thisUser -> deductAmount(myCart.at(i) -> getPrice());
        //subtract one from quanity and the price

      }
      else if (myCart.at(i) -> getPrice() > thisUser -> getBalance())
      {
        tempCart.push_back(myCart.at(i));
      }
      //sumofPrices += (myCart.at(i) -> getPrice() * myCart.at(i) -> getQty());
    }
    //thisUser -> deductAmount(sumofPrices);
    if (tempCart.size() > 0)
    {
      tempCart = userCart.find(thisUser) -> second;
    }
    else if (tempCart.size() == 0)//if user bought everything
    {
      delete[] &myCart;
    }

  }
  //check if user exists
  //if user exists, find his cart
  //Loop through each item and see each price and quantity
  // SEe if its good and hten subtract 
  // See if they have enough money for it 
  // check if in stock if person has money enough to buy (get price and subtract price from balance quantity from stock)
  //If you can't buy add it to the dummy cart;
}

std::vector<Product*> myDataStore::getCart (std::string username) // given string
{
  //User* thisUser = new User(username, double balance, int type)
  std::map<std::string, User*>::iterator it;
  std::vector<Product*> it22;
  std::map<std::string, std::vector<Product*>>::iterator it2;
  //std::map<std::string, User*> thisUser;
  std::cout << username << std::endl;
    if (user_.find(username) != user_.end())
    {
      return userCart.find(user_.find(username) -> second) -> second;
      //cout << 
    }
    return it22;
}
/*{
  std::vector<User*, std::vector<Product>>::iterator it;
  std::map<std::string, User*> thisUser;
  std::map<std::string, Product*> thisProduct;
  std::map<User*, std::vector<Product**>> thisCart;

  for (it = thisCart.begin(); it!= thisCart.end(); ++it)  
  {
    ;
  }

  return thisCart; // return vector product*
  
}*/

std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, int type)
{
  //std::set <Product*>::iterator it;
  std::set <Product*> setProd1;
  std::set <Product*> setProd2;
  std::set <Product*> finalSet;
  //product_ is my map
  std::vector<Product*> cartMatch;
  std::vector <Product*> unionV;
  std::vector <Product*> intersectionV;
  std::vector<std::string>::iterator it;
  std::set <Product*>:: iterator it2;
  bool isthisFirstIndex = true;
  bool isthisFirstIndexI = true;
  if (type == 1)//ORSEARCHUNION 
  {
    for (it = terms.begin(); it != terms.end(); it++)
    {
      if (product_.find(*it) != product_.end())
      {
        if (isthisFirstIndex == true)
        {
          setProd1 = product_.find(*it)->second; // will give me a set
          isthisFirstIndex = false; 
        }
        else
        {
          setProd2 = product_.find(*it) -> second;
          finalSet = setUnion(setProd1, setProd2);
        }
      } 
    }
    for (it2 = finalSet.begin(); it2 != finalSet.end(); it++)
    {
      unionV.push_back(*it2);
    }
    return unionV;
  }
  else if (type == 0)//ANDSEARCHINTERSECTION
  {
    for (it = terms.begin(); it != terms.end(); it++)
    {
      if (product_.find(*it) != product_.end())
      {
        if (isthisFirstIndexI == true)
        {
          setProd1 = product_.find(*it) -> second; // will give me a set
          isthisFirstIndex = false;
        }
        else
        {
          setProd2 = product_.find(*it) -> second;
          finalSet = setIntersection(setProd1, setProd2);
        }
      }
    }
  }
  return intersectionV;
}

void myDataStore:: addtoCart(std::string username, Product* p)
{
  if (user_.find(username) != user_.end())
  {
    if (userCart.find(user_.find(username)->second) != userCart.end()) // he has a cart
    {
      (userCart.find(user_.find(username) -> second)->second).push_back(p); 
    }
    else
    {
      std::vector<Product*> thisaddedCart;
      thisaddedCart.push_back(p);
      userCart.insert(std::pair<User*, std::vector<Product*>>(user_.find(username)->second, thisaddedCart));
    }
  }
  //check if user exists
  //check if user has a cart
  // if they dont ahve a cart have to make one
  // if user's cart exists, add a product to that cart using .push_back
}

void myDataStore:: dump(std::ostream& ofile)
{
  //get all products
  //dump all products
  //dump all users
  
}

