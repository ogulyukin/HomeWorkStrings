/* Гулюкин О.В.
 * Написать рекурсивную функцию которая выводит на экран числа Фибоначчи до указанного предела.
 */
#include <iostream>

using namespace std;
int CalcFibonachi(int iNumber);
int main() {
    setlocale(LC_ALL,"ru");
    int iNumber;
    int iResult = 0;
    cout  << "Программа выводит числа фибоначчи до указанного предела : "  << endl;
    cout << "Введите предел чисел : "; cin >> iNumber;
    for (int i = 1; iResult < iNumber; i++){
        cout  << iResult << "\t";
        iResult = CalcFibonachi(i);
    }
    return 0;
}
int CalcFibonachi(int iNumber) {

    if (iNumber == 1){
        return 1;
    }else if(iNumber == 0){
        return 0;
    }else{
        return (CalcFibonachi(iNumber - 1) + CalcFibonachi(iNumber -2));
    }
}