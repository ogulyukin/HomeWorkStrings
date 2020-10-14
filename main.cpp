/* Гулюкин О.В.
 *
 */
#include <iostream>
#include "functions.cpp"
//#include <Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"ru");
    cout << "Программа переводит числа из одной системы счисления в другую."  << endl;
    cout << "Программа работает ТОЛЬКО с целыми числами!!!" << endl;
    PrintMenu();
    int choise;
    const int n = 256;
    char binary[n];
    double decResult;
    bool check;
    choise = GetChoise();
    while (choise){
        if (!choise){
            return 0;
        }else if (choise == 1){
            cout << "Введите десятичное число : "; cin >> binary;
            check = isNumber(binary);
            if (check){
                decResult = toNumberEq(binary);
                Dec2Bin(decResult);
            }else{
                cout << "введено не число!" << endl;
            }
        }else if (choise == 2){
                cout << "Введите двоичное число : " << endl;
                cin >> binary;
                check = isBinary(binary);
                if (check){
                    decResult = Bin2Dec(binary);
                    cout << "Перевдим число в десятичное : " << decResult << endl;
                }else{
                    cout << "введено не двоичное число!" << endl;
                }
        }else if (choise == 3){
            cout << "Введите десятичное число : "; cin >> binary;
            check = isNumber(binary);
            if (check){
                decResult = toNumberEq(binary);
                Dec2Hex(decResult);
            }else{
                cout << "введено не число!" << endl;
            }
        }else{
            cout << "Введите шестнадцатиричное число : " << endl;
            cin >> binary;
            LowerCase(binary);
            check = isHex(binary);
            if (check){
                decResult = Hex2Dec(binary);
                cout << "Перевдим число в десятичное : " << decResult << endl;
            }else{
                cout << "введено не верное число!" << endl;
            }
        }
        PrintMenu();
        choise = GetChoise();
    }
    return 0;
}
