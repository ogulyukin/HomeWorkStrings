//
// Created by oleg on 13.10.2020.
//
#pragma once
#include <iostream>
#include "functions.h"
#include "math.h"
using namespace std;

void InputLine(char str[], const int n){
    //SetConsoleCP(1251);
    cout << "Enter string : "; cin.getline(str,n);//cin >> str;
    //SetConsoleCP(866);
}
int GetLen(const char str[]){
    int count = 0;
    while(str[count])
        count++;
    return count;
}
void UpperCase(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] > 96 && str[i] < 123){
            str[i] -= 32;
        }
    }
    cout << str << endl;
}
void LowerCase(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] > 64 && str[i] < 91){
            str[i] += 32;
        }
    }
    cout << str << endl;
}
void Capitalize(char str[]){
    if (str[0] > 96 && str[0] < 123){
        str[0] -= 32;
    }
    cout << str << endl;
}
void Shrink(char str[]){
    int len = GetLen(str);
    char *str2 = new char[len];
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < len; i++){
        if (str[i]  != 32){
            str2[count] = str[i];
            count++;
        }else{
            count2++;
        }
        str2[len- count2] = '\0';
    }
    for (int i = 0; i <= (len - count2); i++){
        str[i] = str2[i];
    }
}
bool isPalindrome(char str[]){
    int len = GetLen(str);
    if (!len%2)
        return false;
    int middle = len / 2;
    char *arr01 = new char[middle];
    char *arr02 = new char[middle];
    for (int i = 0; i < middle; i++){
        arr01[i] = str[i];
        arr02[i] = str[len - 1 - i];
    }
    for (int i = 0; i < middle; i++){
        if (arr01[i] != arr02[i])
            return false;
    }
    return true;
}
bool isNumber(char str[]){
    int len = GetLen(str);
    int pointCount= 0;
    for (int i = 0; i < len; i++){
        if(str[i] == 46 || str[i] == 44){
            pointCount++;
            if (pointCount > 1)
                return false;
        }else if (str[i] < 48 || str[i] > 57){
            return false;
        }
    }
    return true;
}
int toNumber(char str[]){
    int result = 0;
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        result += int(str[i]);
    }
    return result;
}
double toNumberEq(char str[]){
    int len = GetLen(str);
    int count = ifDouble(str);
    double result = int(str[len-1]-48);
    if (count == 0){
        for (int i = 2; i <= len; i++){
            result += (int(str[len-i])-48)*pow(10,(i-1));
        }
        return result;
    }else{
        DeletePoint(str);
        len = GetLen(str);
        for (int i = 2; i <= len; i++){
            result += (int(str[len-i])-48)*pow(10,(i-1));
        }
        result = result / pow(10,(len - count));
        return result;
    }


}
int ifDouble(const char str[]) {
    int len = GetLen(str);
    int count = len - 1;
    while (str[count] != '.' && str[count] != ',' && count > 0 ){
        count--;
    }
    return count;
}
void DeletePoint(char str[]){
    int len = GetLen(str);
    char *str2 = new char[len];
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < len; i++){
        if (str[i]  != '.' && str[i] != ','){
            str2[count] = str[i];
            count++;
        }else{
            count2++;
        }
        str2[len- count2] = '\0';
    }
    for (int i = 0; i <= (len - count2); i++){
        str[i] = str2[i];
    }
}