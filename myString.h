#ifndef myString_h
#define myString_h


#include <string>
#include <vector>
#include <iostream>



class myString{

    std::vector<char> chars;
    int len =0;

public:
    myString(std::string str){
    for(int i = 0; i < str.length(); i++){
        chars.push_back(str.at(i));
        len++;
    }
    }

    ~myString(){
        while( len > 1){
            chars.pop_back();
            len--;
        }
    }
    /**
     * Function returns an STD::STRING of the myString
    */

    std::string toString();

    /**
     * Function returns length of the string
    */
    int length();

    /**
     * Functions below return a substring, can be used with one or two params. 
     * Two params will return a string from start to end that is specified and one 
     * will return start to end of the string
    */
    myString subString(int start);

    myString subString(int start, int end);

    /**
     * Overloads the + and += operator to allow for str to be concatonated to eachother
    */
    myString operator+(myString str);

    void operator+=(myString str);

    /**
     * Overloads the [i] selection operator to reference a char at index i
     * returns ~ if index is invalid
    */

   char operator[] (int i);

   /**
    * Overloads for the comparison operators and compares them lexographically
   */
  bool operator==(myString str);

  bool operator!=(myString str);

  bool operator<(myString str);

  bool operator>(myString str);

  bool operator<=(myString str);

  bool operator>=(myString str);

  /**
   * reassignments of the assignment and copy constructor
  */
    myString operator=(myString &str);

    myString(myString &str){
        myString temp = myString("");
        for(int i =0; i < str.length(); i++){
            temp.chars.push_back(str[i]);
            temp.len++;
        }
    }

    /**
     * redifinition of << operator for output streams
    */
    //std::ostream& operator<<(std::ostream& os);
};

#endif