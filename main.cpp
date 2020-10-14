/* Гулюкин О.В.
 * Это вариант для работы с латинскими символами, в UTF-8 кириллица кодируется двумя байтами и не влезает
 * в тип данных char. разобраться с тем как работать с UTF не смог ((
 * (на линухе я не знаю как переключать кодировку в консоли)
 */
#include <iostream>
#include "functions.cpp"
//#include <Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"ru");
    const int n = 256;
    bool result;
    double resultNumber;
    char str[n];
    cout << "This program is show how strings can work! It can work only with Latin symbols!!!" << endl;
    cout << "You may exit by press enter in any time." << endl;
    InputLine(str, n);
    while(str[0] != 0){
        cout << "Making all CAPS symbols:" << endl;
        UpperCase(str);
        cout << "Now lets lower them all:" << endl;
        LowerCase(str);
        result = isPalindrome(str);
        if(!result){
            cout << "String is NOT a Palidrome!" << endl;
        }else{
            cout << "String IS a Palidrome!" << endl;
        }
        cout << "Not let the first Symbol become UP!" << endl;
        Capitalize(str);
        Shrink(str);
        cout << "Deleting spaces if present:" << endl;
        cout << str << endl;
        result = isNumber(str);
        if(!result){
            cout << "String is not a Number!!!" << endl;
            resultNumber = toNumber(str);
            cout << "String to number result is : " << resultNumber << endl;
        }else{
            cout << "String is a Number!!!" << endl;
            resultNumber = toNumberEq(str);
            cout << "Converting it to Number : " << resultNumber << endl;
        }
        str[0] = 0;
        InputLine(str, n);
    }
    return 0;
}
