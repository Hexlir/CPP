#pragma once

#include "bits/stdc++.h"
#include "iomanip"

using namespace std;

void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

class Warning{
    public:
        string what(){
            return "\033[1;31mInput Salah!\033[0m";
        }
};

bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

bool isEmpty(string s){
    if(s == ""){
        return true;
    }
    return false;
}

bool isInRange(int n, int min, int max){
    if(n >= min && n <= max){
        return true;
    }
    return false;
}

void getInputWithSpace(string &s){
    cin.ignore();
    getline(cin, s);
}