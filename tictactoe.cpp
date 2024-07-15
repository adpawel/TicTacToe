#include "tictactoe.h"

TicTacToe::TicTacToe() {
    reset();
}
void TicTacToe::makeMove(int x, int y, QString player){
    board[x][y] = player;
}
bool TicTacToe::checkWin()
{
    for (int i = 0; i < 3; ++i) {
        if (!board[i][0].isEmpty() && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
        if (!board[0][i].isEmpty() && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }
    if (!board[0][0].isEmpty() && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }
    if (!board[0][2].isEmpty() && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }
    return false;
}
bool TicTacToe::isBoardFull(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j].isEmpty()) {
                return false;
            }
        }
    }
    return true;
}
void TicTacToe::reset(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = "";
        }
    }
}
