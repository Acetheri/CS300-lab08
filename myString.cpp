#include "myString.h"






const int myString::size(){
    return length;
}



myString myString::substr(int start){
    char temp[length] = "";
    int j = 0;
    for(int i = start; i < length; i++){
        temp[j] = chars.at(i);
        j++;
    }
    myString output = myString(temp);
    return output;
}

myString myString::substr(int start, int end){
    char temp[end-start];
    int j = 0;
    for(int i = start-1; i < length; i++){
        if(j < length-start) temp[j] = chars.at(i);
        j++;
    }
    myString output = myString(temp);
    return output;
}

 myString myString::operator+(myString& str){
    int len1 = length;
    int len2 = str.size();
    char temp[len1 + len2];
    int j =0;
    for(int i = 0; i < len1; i++){
        temp[j] = chars.at(i);
        j++;
    }
    for(int k = 0; k < len2; k++){
        temp[j] = str.chars.at(k);
        j++;
    }
    myString output = myString(temp);
    return output;
}

void myString::operator+=(myString& str){
    for(int i =0; i < str.size(); i++){
        chars.push_back(str.chars.at(i));
    }
    return;
}

const char myString::operator[](int index){
    return chars.at(index);
}

const bool myString::operator==(myString& str){
    if(length != str.size()) return false;
    for(int i = 0; i < length; i++){
        if(chars.at(i) != str[i]) return false;
    }
    return true;
}

const bool myString::operator!=(myString& str){
    if(length != str.size()) return true;
    for(int i = 0; i < length; i++){
        if(chars.at(i) != str[i]) return true;
    }
    return false;
}

const bool myString::operator<( myString& str){
    int len1 = length;
    int len2 = str.size();
    if(operator==(str) == true) return false;
    if(len1 > len2){
        for(int i = 0; i < len2; i++){
            if(chars.at(i) > str[i]) return false;
        }
        return false;
    } else{
        for(int i =0; i < len1; i++){
            if(chars.at(i) > str[i]) return false;
        }
        return true;
    }
}
const bool myString::operator<=( myString& str){
    int len1 = length;
    int len2 = str.size();
    if(operator==(str) == true) return true;
    if(len1 > len2){
        for(int i = 0; i < len2; i++){
            if(chars.at(i) > str[i]) return false;
        }
        return true;
    } else{
        for(int i =0; i < len1; i++){
            if(chars.at(i) > str[i]) return false;
        }
        return false;
    }
}
const bool myString::operator>( myString& str){
    int len1 = length;
    int len2 = str.size();
    if(operator==(str) == true) return false;
    if(len1 > len2){
        for(int i = 0; i < len2; i++){
            if(chars.at(i) > str[i]) return true;
        }
        return false;
    } else{
        for(int i =0; i < len1; i++){
            if(chars.at(i) > str[i]) return true;
        }
        return true;
    }
}
const bool myString::operator>=( myString& str){
    int len1 = length;
    int len2 = str.size();
    if(operator==(str) == true) return true;
    if(len1 > len2){
        for(int i = 0; i < len2; i++){
            if(chars.at(i) > str[i]) return true;
        }
        return false;
    } else{
        for(int i =0; i < len1; i++){
            if(chars.at(i) > str[i]) return true;
        }
        return true;
    }
}


int main(){

    char temp1[] = "hello";
    char temp2[] = "world";

    myString test1 = myString(temp1);
    myString test2 = myString(temp2);
    

    std::cout << test1 << std::endl;


    myString test3 = test1.substr(1);

    std::cout << test3 << std::endl;

    std::cout << (test1 < test2) << std::endl;

    std::cout << (test1 > test2) << std::endl;

    std::cout << (test3 == test2) << std::endl;

    //test3 = (test1 + test2);

    //std::cout <<  << std::endl;








}