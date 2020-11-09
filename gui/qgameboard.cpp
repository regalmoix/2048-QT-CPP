#include "gui/qgameboard.h"
#include "gui/qtile.h"
#include "gui/qresetbutton.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>

#include <iostream>

#include <math.h>

#include <core/global.h>

QGameBoard::~QGameBoard()
{
    //delete game;
}

QGameBoard::QGameBoard(QWidget *parent) : QWidget(parent)
{
    // set default size
    resize(650,450);

    //std::vector<vector<int>> myboard(4, vector<int> (4,0));
    //boardinit(4);



    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // will be created in drawBoard()
    boardLayout = NULL;

    // create the gui board and draw it
    gui_board.resize(4);

    myboard.resize(4);

    for (int i = 0; i < 4; ++i)
    {
        gui_board[i].resize(4);
        myboard[i].resize(4);
    }

    boardinit(4);

    input(myboard, 4);
        
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            gui_board[i][j] = NULL;
            //myboard[i][j] = 4;    
        }
    }

    

    drawBoard();

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(420));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}


// Currently Only Prints to console
void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    
    switch (event->key()) 
    {
        case Qt::Key_Up:
            qDebug() << "up";
            up(myboard ,4);
            break;
        case Qt::Key_Left:
            qDebug() << "left";
            left(myboard ,4);
            break;
        case Qt::Key_Right:
            qDebug() << "right";
            right(myboard ,4);
            break;
        case Qt::Key_Down:
            qDebug() << "down";
            down(myboard ,4);
            break;
    }

    emptycell(myboard, 4);

    if (emptypos.empty() && !checkmove(myboard, 4))
    {
        /*
            //move(6*n, 0);
            system("clear");
            printf("\n\nGame Ended, Out of Moves.\nFinal Score : %d \nPress any key to quit.", score);
            cin.get();
            //return endwin();
            return 0;
        */
        resetGame();        //?? or is it?

    }

    addrandom(myboard);
    emptycell(myboard, 4);

    drawBoard();
}

void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j) 
        {
            delete gui_board[i][j];
            int x = myboard[i][j];

            //cin >> x;

            
            gui_board[i][j] = new QTile(x);
            
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}

//Change to Close Game
void QGameBoard::resetGame()
{
    //game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(420));
    gameOverWindow.hide();
}
