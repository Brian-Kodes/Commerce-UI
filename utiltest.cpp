#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include "util.h"
#include "book.h"
#include "product.h"
using namespace std;

int main(int argc, char* argv[])
{

  set <string> newString;
  set <string> newString2;

  set <string> wordSet1;
  set <string> wordSet2;
  wordSet1.insert("purple");
  wordSet1.insert("black");
  wordSet2.insert("purple");
  wordSet2.insert("blue");
  wordSet2.insert("green");
  wordSet1.insert("works");
  //cout << wordSet1();

  //Book *book = new Book("10100101", "Michael M",  "Fiction",  "Of Mice and Men", 19.99, 3);
  //Book(string isbn, string author, const std::string category, const std::string name, double price, int qty);


  //string inputWords = "Purple, Sally,! Salamander,, Salmon, Wow!Gizzle, FizzlePOP, Men's T-Shirt";
  string inputWords1 = "Purple, Sally,! Salamander,, Salmon, Wow!Gizzle, FizzlePOP, Men's T-Shirt";

  newString = parseStringToWords(inputWords1);
  std::set <std::string>::iterator it;
  for (it = newString.begin(); it != newString.end(); it++) //test function
  {
    std::cout << *it << std::endl;
  }

  //newString = setIntersection(wordSet1, wordSet2);
  //newString2 = setUnion(wordSet1, wordSet2);
  typename std:: set<string>::iterator its1;
  //cout << newString[]
  //for (its1 = newString.begin(); its1 != newString.end(); its1++)
  //{
    //cout << *its1 << endl;
  //}


  
}