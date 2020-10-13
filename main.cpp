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
            cout << "Введите десятичное число : "; cin >> decResult;
            Dec2Bin(decResult);
        }else if (choise == 2){
                cout << "Введите двоичное число : " << endl;
                cin >> binary;
                check = isBinary(binary);
                if (!check)
                    cout << "введено не двоичное число!" << endl;
            decResult = Bin2Dec(binary);
            cout << "Перевдим число в десятичное : " << decResult << endl;
        }else if (choise == 3){

        }else{

        }
        PrintMenu();
        choise = GetChoise();
    }
    return 0;
}
