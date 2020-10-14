//
// Created by oleg on 13.10.2020.
//
#pragma once
#include <iostream>
#include "functions.h"
#include "math.h"
using namespace std;

void Dec2Bin(int decimal){
    int resultDiv;
    char resultBin[256];
    int count = 0;
    do{
        resultDiv = decimal%2;
        if (resultDiv){
            resultBin[count] = '1';
        }else{
            resultBin[count] = '0';
        }
        decimal /= 2;
        count++;
    }while (decimal >= 1);
    resultBin[count+1] = 0;
    int len = GetLen(resultBin);
    char *finalResult = new char[len];
    for (int i = 1; i <= len; i++){
        finalResult[i-1] = resultBin[len-i];
    }
    finalResult[len] = 0;
    cout << "Переводим из десятичного в двоичное число: " << endl;
    cout << finalResult << endl;
}
double Bin2Dec(char binary[]){
    int len = GetLen(binary);
    double result = 0;
    int count = 0;
    for (int i = len-1; i >=0; i--){
        result += int(binary[i] - 48) * pow(2, count);
        count++;
    }
    return result;
}
void Dec2Hex(int decimal){
    int resultDiv;
    char resultHEX[256];
    int count = 0;
    do{
        resultDiv = decimal%16;
        GetHexSymbol(resultHEX,count,resultDiv);
        decimal /= 16;
        count++;
    }while (decimal >= 16);
    GetHexSymbol(resultHEX,count,decimal);
    resultHEX[count+1] = 0;
    int len = GetLen(resultHEX);
    char *finalResult = new char[len];
    for (int i = 1; i <= len; i++){
        finalResult[i-1] = resultHEX[len-i];
    }
    cout << resultHEX << endl;
    finalResult[len] = 0;
    cout << "Переводим из десятичного в шеснадцатеричное число: " << endl;
    cout << finalResult << endl;
}
int Hex2Dec(char hex[]){
    int len = GetLen(hex);
    double result = 0;
    int count = 0;
    for (int i = len-1; i >=0; i--){
        if(hex[i] >=48 && hex[i] <=57){
            result += int(hex[i] - 48) * pow(16, count);
        }else{
            result += int(hex[i] - 87) * pow(16, count);
        }
        count++;
    }
    return result;
}
int GetLen(const char str[]){
    int count = 0;
    while(str[count])
        count++;
    return count;
}
int GetChoise(){
    int choise;
    do{
        cout << "Выберите действие : "; cin >> choise;
    }while (choise > 4 || choise < 0);
        return choise;
}
bool isBinary(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] < 48 || str[i] > 49){
            return false;
        }
    }
    return true;
}
void PrintMenu(){
    cout << "1 - Преобразует десятичное число в двоичное." << endl;
    cout << "2 - Преобразует двоичное число в десятичное" << endl;
    cout << "3 - Преобразует десятичое число в HEX" << endl;
    cout << "4 - Преобразует HEX в десятичное число" << endl;
    cout << "0 - Выход" << endl;
}
void GetHexSymbol(char hex[], int count, int decimal){
    if (decimal <= 9){
        hex[count] = decimal + 48;
    }else{
        hex[count] = decimal + 87;
    }
}
bool isHex(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] < 48 || str[i] > 57){
            if (str[i] < 97 || str[i] > 102)
                    return false;
        }
    }
    return true;
}
void LowerCase(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] > 64 && str[i] < 91){
            str[i] += 32;
        }
    }
}
double toNumberEq(char str[]){
    int len = GetLen(str);
    double result = int(str[len-1]-48);
    for (int i = 2; i <= len; i++){
        result += (int(str[len-i])-48)*pow(10,(i-1));
    }
    return result;
}
bool isNumber(char str[]){
    int len = GetLen(str);
    for (int i = 0; i < len; i++){
        if (str[i] < 48 || str[i] > 57){
            return false;
        }
    }
    return true;
}