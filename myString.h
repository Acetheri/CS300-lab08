#ifndef myString_h
#define myString_h



#include <cstring>
#include <vector>
#include <iostream>

class myString{
    std::vector<char> chars;
    int length = 0;

public:

myString(char array[]){
    for(int i = 0;i < strlen(array); i++){
        chars.push_back(array[i]);
        length++;
    }
}
~myString(){
    for(int i =0; i <= length; i++){
        chars.pop_back();
        length--;
    }
}

const int size();


myString substr(int start);

myString substr(int start, int end);

myString operator+( myString& str);

void operator+=( myString& str);

const char operator[](int index);

const bool operator==( myString& str);

const bool operator!=( myString& str);

const bool operator<( myString& str);

const bool operator<=( myString& str);

const bool operator>( myString& str);

const bool operator>=( myString& str);


const myString operator=( myString& str){
    char temp[str.size()];
    for(int i = 0; i < str.size(); i++){
        temp[i] = str[i];
    }
    myString output = myString(temp);
    return output;
}


friend std::ostream& operator<<(std::ostream& os, myString& str){
    for(int i = 0; i < str.size(); i++){
        os << str[i];
    }
    return os;
}

};
#endif