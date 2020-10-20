//
// Created by oleg on 13.10.2020.
//
#pragma once
#include <iostream>
#include "functions.h"
#include "math.h"
#include "string.h"
using namespace std;

void InputLine(char str[], const int n){
    //SetConsoleCP(1251);
    cout << "Enter string : "; cin.getline(str,n);//cin >> str;
    //SetConsoleCP(866);
}
int GetLen(const char str[]){
    int len = strlen(str);
    return len;
}
void UpperCase(char str[]){
    int len = strlen(str);
    bool Cyrillick;
    for (int i = 0; i < len; i++){
        if (str[i] > 96 && str[i] < 123){
            str[i] -= 32;
        }
        Cyrillick = isCyrillick(str[i]);
        if (Cyrillick){
            UpperCaseCyr(str, i);
            i++;
        }

    }
    cout << str << endl;
}
void LowerCase(char str[]){
    int len = GetLen(str);
    bool Cyrillick;
    for (int i = 0; i < len; i++){
        if (str[i] > 64 && str[i] < 91){
            str[i] += 32;
        }
        Cyrillick = isCyrillick(str[i]);
        if (Cyrillick){
            LowerCaseCyr(str, i);
            i++;
        }
    }
    cout << str << endl;
}
void Capitalize(char str[]){
    if (str[0] > 96 && str[0] < 123){
        str[0] -= 32;
    }
    bool Cyr = isCyrillick(str[0]);
    if (Cyr){
        UpperCaseCyr(str, 0);
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
    bool Cyr;
    for (int i = 0; i < len; i++){
        Cyr = isCyrillick(str[i]);
        if (Cyr){
            cout << "Entered string contain cyrillic symbols! cant determine if it is a palidrome or not!" << endl;
            return false;
        }
    }
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
bool isCyrillick(char symbol){
    if (int(symbol) == -48 || int(symbol) == -47){
        return true;
    }
    return false;
}
void UpperCaseCyr(char str[], int index){
    //char temp[3]{str[index],str[index+1],0};
    //cout << "символ : " << temp << endl;
    //cout << "в цифрах : " << index << "\t" << int(str[index]) << "\t" << int(str[index+1]) << endl;
    if (str[index] == -47 && str[index+1] == -111){ //ё - исключение
        str[index+1] = -127;
        str[index] = -48;
        //temp[0] = str[index];
        //temp[1] = str[index+1];
        //cout << "1символ после : " << temp << endl;
        //cout << "в цифрах : " << int(str[index]) << "\t" << int(str[index+1])<< endl;
        return;
    }else if (str[index] == -48 && str[index+1] >= -80 && str[index+1] <= -65){ //от а до п
        str[index+1] -= 32;
        //temp[0] = str[index];
        //temp[1] = str[index+1];
        //cout << "2символ после : " << temp << endl;
        //cout << "в цифрах : " << int(str[index]) << "\t" << int(str[index+1]) << endl;
        return;
    }else if(str[index] == -47 && str[index+1] >= -128 && str[index+1] <= -113){ //от р до я
        str[index + 1] += 32;
        str[index] = -48;
        //temp[0] = str[index];
        //temp[1] = str[index+1];
        //cout << "3символ после : " << temp << endl;
        //cout << "в цифрах : " << int(str[index]) << "\t" << int(str[index+1]) << endl;
    }
}
void LowerCaseCyr(char str[], int index){
    if (str[index] == -48 && str[index+1] == -127){
        str[index+1] = -111;
        str[index] = -47;
        return;
    }else if (str[index +1] >= -96 ){
        str[index+1] -= 32;
        str[index] = -47;
        return;
    }else{
        str[index + 1] += 32;
    }
}