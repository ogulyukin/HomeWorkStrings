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

}
int Hex2Dec(char hex[]){
    return 0;
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