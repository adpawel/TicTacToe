#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <QString>

class TicTacToe
{
public:
    TicTacToe();

    void makeMove(int x, int y, QString player);
    bool checkWin();
    bool isBoardFull();
    void reset();
private:
    QString board[3][3];
};

#endif // TICTACTOE_H
