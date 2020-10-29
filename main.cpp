/* Гулюкин О.В.
 * Написать рекурсивную функцию которая выводит на экран числа Фибоначчи до указанного предела.
 */
#include <iostream>

using namespace std;
int CalcFibonachi(int iNumber);
int main() {
    setlocale(LC_ALL,"ru");
    int iNumber;
    cout  << "Программа выводит числа указанное количество чисел фибоначчи "  << endl;
    cout << "Введите количество чисел : "; cin >> iNumber;
    for (int i = 0; i < iNumber; i++){
        cout  << CalcFibonachi(i) << "\t";
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