#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool Account_Validation(string *n, vector<string> Username){
    for(int i = 0; i < Username.size(); ++i){
        if((*n) == Username[i])
            return false;
    }
    return true;
}

bool Password_Validation(string *n){
    int num, alpha;
    num = 0, alpha = 0;
    for(int i = 0; i <(*n).length(); ++i){
        if(int((*n)[i]) >= 48 && int((*n)[i]) <= 57){
            ++num;
        }
        else if((int((*n)[i]) >= 65 && int((*n)[i]) <= 90) || ((int((*n)[i]) >= 97 && int((*n)[i]) <= 122))){
            ++alpha;
        }
        if(num>0 && alpha>0){
            return true;
        } 
    }
    return false;
}

int Search_key(string *n, vector<string> Username){
    for(int i = 0; i < Username.size(); ++i){
        if((*n) == Username[i]){
            return i;
        }
    }
}