#include "myString.h"


std::string myString::toString(){
    std::string temp = "";
    for(int i = 0; i < len; i++){
        temp += chars.at(i);
    }
    return temp;
}

int myString::length() {
    return len;
}


myString myString::subString(int start){
    std::string temp = "";
    for(int i = start; i < len; i++){
        temp+= chars.at(i);
    }
    return myString(temp);
}
myString myString::subString(int start, int end){
    std::string temp = "";
    for(int i = start; i < end; i++){
        temp+= chars.at(i);
    }
    return myString(temp);
}

myString myString::operator+(myString str){
    myString temp = subString(0);
    int len2 = str.len;
    for(int i = 0; i < len2; i++){
        temp.chars.push_back(str.chars.at(i));
        temp.len++;
    }
    return temp;
}

myString myString::operator+=(myString str){
    int len2 = str.len;
    for(int i = 0; i < len2; i++){
        chars.push_back(str.chars.at(i));
        len++;
    }
}

char myString::operator[](int i) {
    if(!(i >= 0 || i < len)){
    return chars.at(i); 
    } else {
        return '~';
    }
    }

bool myString::operator==(myString str) {
    if(str.length() != this->length()) return false;
    for(int i = 0; i < this->length(); i++){
        if(this->chars.at(i) != str.chars.at(i)) return false;
    }
    return true;
}

bool myString::operator!=(myString str){
    if(str.length() != this->length()) return true;
    for(int i = 0; i < this->length(); i++){
        if(this->chars.at(i) != str.chars.at(i)) return true;
    }
    return false;
}

bool myString::operator<(myString str){
    if(operator==(str) == true) return false;
    if(len >= str.len){
        for(int i = 0; i < len; i++){
            if(str[i] == '~') return false;
            if(chars.at(i) < str[i]) return true;
            if(chars.at(i) > str[i]) return false;
        }
    } else {
        for(int i = 0; i < str.len; i++){
            if(chars.at(i) == '~') return false;
            if(chars.at(i) < str[i]) return true;
            if(chars.at(i) > str[i]) return false;
        }
    }
}

bool myString::operator>(myString str){
    if(operator==(str) == true) return false;
    if(len >= str.len){
        for(int i = 0; i < len; i++){
            if(str[i] == '~') return false;
            if(chars.at(i) > str[i]) return true;
            if(chars.at(i) < str[i]) return false;
        }
    } else {
        for(int i = 0; i < str.len; i++){
            if(chars.at(i) == '~') return false;
            if(chars.at(i) > str[i]) return true;
            if(chars.at(i) < str[i]) return false;
        }
    }
}

bool myString::operator<=(myString str){
    if(operator==(str) == true) return true;
    if(len >= str.len){
        for(int i = 0; i < len; i++){
            if(str[i] == '~') return false;
            if(chars.at(i) < str[i]) return true;
            if(chars.at(i) > str[i]) return false;
        }
    } else {
        for(int i = 0; i < str.len; i++){
            if(chars.at(i) == '~') return false;
            if(chars.at(i) < str[i]) return true;
            if(chars.at(i) > str[i]) return false;
        }
    }
}

bool myString::operator>=(myString str){
    if(operator==(str) == true) return true;
    if(len >= str.len){
        for(int i = 0; i < len; i++){
            if(str[i] == '~') return false;
            if(chars.at(i) > str[i]) return true;
            if(chars.at(i) < str[i]) return false;
        }
    } else {
        for(int i = 0; i < str.len; i++){
            if(chars.at(i) == '~') return false;
            if(chars.at(i) > str[i]) return true;
            if(chars.at(i) < str[i]) return false;
        }
    }
}

myString myString::operator=(myString &str){
    myString(*str);
}