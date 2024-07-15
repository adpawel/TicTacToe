#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "tictactoe.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
private:
    Ui::MainWindow *ui;
    QPushButton* buttons[3][3];
    TicTacToe game;
    bool playerX = true;

    void resetBoard();
    void checkGameStatus();
};
#endif // MAINWINDOW_H
