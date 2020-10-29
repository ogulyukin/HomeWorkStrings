/* Гулюкин О.В.
 * Написать программу игря в крестики - нолики
 */
#include <iostream>
using namespace std;
void TurnMake(char board[][3]);
void IITurnMake(char board[][3]);
void DrawScene(char board[][3]);
bool CheckWinner(char board[][3], char win);
bool CheckNoWin(char board[][3]);
int RandomNumber();
int main()
{
    const int SIZE = 3;
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool winX;
    bool winO;
    bool noWin;
    DrawScene(board);
    do {
        cout << "Ход Крестика" << endl;
        TurnMake(board);
        DrawScene(board);
        winX = CheckWinner(board, 'X');
        noWin = CheckNoWin(board);
        if (winX || noWin)
            break;
        cout << "Ход Нолика" << endl;
        IITurnMake(board);
        DrawScene(board);
        winO = CheckWinner(board, '0');
        noWin = CheckNoWin(board);
    } while (!winX && !winO && !noWin);
    if (winX) {
        cout << "Выиграл Крестик!" << endl;
    }
    if (winO) {
        cout << "Выиграл Нолик!" << endl;
    }
    if (noWin)
        cout << "Ничья!" << endl;
}
void TurnMake(char board[][3]){
    int x,y;
    do {
        do {
            cout << "Введите первую координату : "; cin >> x;
            cout << "Введите вторую координату : "; cin >> y;
        } while (x < 0 || y < 0 || x > 2 || y > 2);
    } while (board[x][y] == '0' || board[x][y] == 'X');
    board[x][y] = 'X';
}
void IITurnMake(char board[][3]){
    int x,y;
    do {
        do {
            x = RandomNumber();
            y = RandomNumber();
        } while (x < 0 || y < 0 || x > 2 || y > 2);
    } while (board[x][y] == '0' || board[x][y] == 'X');
    board[x][y] = '0';
}
void DrawScene(char board[][3]){
    system ("clear"); //Системная команда Linux для Windows используйте cls
    cout << "---------" << endl;
    for (int i = 0; i <= 2; i++){
        for (int j = 0; j < 1; j++){
            cout << board[i][j] << " | " << board[i][j + 1] << " | " << board[i][j +2] << endl;
            cout << "---------" << endl;
        }
        cout << endl;
    }
}
int RandomNumber(){
    system ("sleep 1"); // Системенная команда Linux для Windows используйте pause 1
    srand(time(nullptr));
    int res = rand()%3;
    return res;
}
bool CheckWinner(char board[][3], char win){
    bool winXO = false;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 1; j++) {
            if (board[i][j] == win && board[i][j+1] == win && board[i][j+2] == win) {
                winXO = true;
                break;
            }
            if (board[j][i] == win && board[j + 1][i] == win && board[j + 2][i] == win) {
                winXO = true;
                break;
            }
        }
    }
    if (board [0][0] == win && board [1][1] == win && board [2][2] == win){
        winXO = true;
    }
    if (board [2][0] == win && board [1][1] == win && board [0][2] == win){
        winXO = true;
    }
    return winXO;
}
bool CheckNoWin(char board[][3]){
    bool noWin = true;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (board[i][j] == ' ')
                noWin = false;
        }
    }
    return noWin;
}
