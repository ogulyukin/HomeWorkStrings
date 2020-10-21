/* Гулюкин О.В.
 * Есть файл "202center.txt", из него нужно сделать файл типа 202.dhcpd.
 */
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL,"ru");
    ifstream file;
    file.open("202center.txt");
    if (!file.is_open()){
        cout << "Ошибка открытия файла!!!" << endl;
        return 10;
    }
    ofstream resFile;
    resFile.open("202.dhcpd");
    if (!resFile.is_open()){
        cout << "Ошибка записи в файл!!!" << endl;
        return 15;
    }
    char aIpAdress[16];
    char aMacAdress[18];
    int iCount = 1;
    while(!file.eof()){
        file >> aIpAdress;
        file >> aMacAdress;
        resFile << "host 202-" << iCount << endl;
        resFile << "{" << endl;
        resFile << "\t" << "hardware ethernet" << "\t" << aMacAdress << ";" << endl;
        resFile << "\t" << "fixed-address" << "\t\t" << aIpAdress << ";" << endl;
        resFile << "}" << endl << endl;
        iCount++;
    }
    file.close();
    return 0;
}
