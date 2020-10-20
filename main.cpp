/* Гулюкин О.В.
 * Это вариант для работы с латинскими символами, в UTF-8 кириллица кодируется двумя байтами и не влезает
 * в тип данных char.
 * added 20.102020 :
 * Проделана следующая рабта - я создал программку которая вывела мне на экран все буквы русского алфавита и приведенные
 * к int значения каждых последовальных друх байт чилес соответствующих им. После записи этой информации в файл у меня
 * получилась кодировка для каждой из букв. Первый сивол был равен или -48 (до "п") или -47 (от р). Далее второй А = -112, Я = -81 и
 * для маленьких букв а = -80 до п = -65, начиная с "р" первый байт уже равен -47 и второй идет от -128 до -113 у "я"
 * отдельно почему-то идет буква "Ё" и "ё". у них значения -48 -127 и -47 -111
 * Удалось сделать все функции кроме палидрома - не стал заморачиваться - уж больно кучерявый код выходит если ввести смесь
 * кириллицы и латиницы...
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
    cout << "This program is show how strings can work! It can work now work even with cyrillic symbols!" << endl;
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
