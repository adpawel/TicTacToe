#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons[0][0] = ui->button00;
    buttons[0][1] = ui->button01;
    buttons[0][2] = ui->button02;
    buttons[1][0] = ui->button10;
    buttons[1][1] = ui->button11;
    buttons[1][2] = ui->button12;
    buttons[2][0] = ui->button20;
    buttons[2][1] = ui->button21;
    buttons[2][2] = ui->button22;

    for(int i=0; i < 3; ++i){
        for(int j=0; j < 3; ++j){
            connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button->text() == "") {
        button->setText(playerX ? "X" : "O");
        int x = -1, y = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (buttons[i][j] == button) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) break;
        }
        game.makeMove(x, y, playerX ? "X" : "O");
        playerX = !playerX;
        checkGameStatus();
    }
}

void MainWindow::checkGameStatus()
{
    if (game.checkWin()) {
        QMessageBox::information(this, "Koniec gry", QString("Gracz %1 wygrywa!").arg(playerX ? "O" : "X"));
        resetBoard();
    } else if (game.isBoardFull()) {
        QMessageBox::information(this, "Koniec gry", "Remis!");
        resetBoard();
    }
}

void MainWindow::resetBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j]->setText("");
        }
    }
    game.reset();
    playerX = true;
}
