/* Гулюкин О.В.
 * Написать рекурсивную функцию Power, которая возводит указанное число, в указанную степень. Основание и показатель
 * степени вводятся с клавиатуры;
 */
#include <iostream>
#include "math.h"
using namespace std;
int Power(int iNumber, int iIndex);
int main() {
    setlocale(LC_ALL,"ru");
    int iNumber, iIndex;
    cout  << "Программа возводить в степень лубое целое число"  << endl;
    cout << "Введите основание : "; cin >> iNumber;
    cout << "Введите степень : "; cin >> iIndex;
    cout << "Проверка  pow : " << pow(iNumber, iIndex) << endl;
    cout << "Результат : " << Power(iNumber, iIndex) << endl;
    return 0;
}
int Power(int iNumber, int iIndex){
    //cout << "iIndex = " << iIndex << "\t";
    if (iIndex == 0)
        return 1;
    if (iIndex == 1)
        return iNumber;
    int result = iNumber * Power(iNumber, iIndex - 1);
    //cout << "result = " << result << endl;
    return result;
}