#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "util.h"
#include "string.h"
#include <vector> //added this ask cp

std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(std::string rawWords)
{
  //rawWords = "Sally,! Salamander,, Salmon, Wow!Gizzle, FizzlePOP, Men's T-Shirt";
  std::set<std::string> newString;
  std::string newWord;
  std::string temp = " ";
  for (unsigned int i = 0; i < rawWords.size(); i++)
  {
    if (ispunct(rawWords[i]) || isspace(rawWords[i]))
    {
        if (newWord != "")
        {
          if (newWord.size() >= 2)
          {
          newWord = convToLower(newWord);
          newString.insert(newWord);
          }
          newWord = "";
        }
    }
    else if (i == rawWords.size() - 1)
    {
      if (newWord != "")
      {
        newWord += rawWords[i];
        newWord = convToLower(newWord);
        newString.insert(newWord);
      }
    }
    else
    {
      newWord += rawWords[i];
    }
  }
  std::set <std::string>::iterator it;
  for (it = newString.begin(); it != newString.end(); it++) //test function
  {
    std::cout << *it << std::endl;
  }
    /*rawWords = "Sally, Salamander, Salmon";
  stringstream s_stream (rawWords);
  set<string> newString;
  string keyLetters;
  string keyWord;
  while (s_stream >> keyLetters)
  {
    cout << keyLetters << endl;*/ /// part 1
    /*if (ispunct(rawWords[i]) == 1) // no punctuation
    {
      getline (s_stream, keyWords, rawWords[i]);
      if (keyWords.size() >= 2)
      {
        cout << keyWords << endl;
        newString.insert(keyWords);
      }
      else
      {
        newString.erase(keyWords);
      }
    }
    else
    {
      ;
    }
  }*/
   /* if (rawWords.size() < 2)
    {
        return;
    }
    else if (rawWords.size() >= 2)
    {
      for (int i = 0; i < rawWords.size(); i++ )
      {
        if (ispunct(rawWords[i] == 0) //if there is no punctuation mark at this index
        {
          stringstream s_stream(rawWords);
          set<string> newString;
          string keyW
        }
        else if (ispunct(rawWords[i] == 1)) //if there is punctuation mark at this index
        {

        }
      }
    }*/
  
  /*rawWords = "Sally, Salamander, Charizard";
  stringstream s_stream(rawWords);
  set<string> newString;
  string keyWords;
  while (s_stream.good())
  {
    string substr;
    getline (s_stream, substr, ',');
    if (substr.size() >= 2)
    {
      cout << substr << endl;
      newString.insert(substr);
    }
  }*/
    return newString;


}













/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
