#include "gui/qgameboard.h"
#include "gui/qtile.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>



#include <core/global.h>

QGameBoard::~QGameBoard()
{
    //delete game;
}

QGameBoard::QGameBoard(QWidget *parent) : QWidget(parent)
{
    // set default size
    resize(650,450);

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
    score = new QLabel(QString("SCORE: %1").arg(gamescore));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    //connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}


// Currently Only Prints to console
void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    auto old_board = myboard;

    switch (event->key()) 
    {
        case Qt::Key_Up:
            up(myboard, 4);
            doCalc();
            break;

        case Qt::Key_Left:
            left(myboard, 4);
            doCalc();       
            break;

        case Qt::Key_Right:
            right(myboard, 4);
            doCalc();
            break;

        case Qt::Key_Down:
            down(myboard, 4);
            doCalc();
            break;

        case Qt::Key_Q :
            resetGame();
            break;
    }

    if (old_board != myboard)
    {
        addrandom(myboard);
        emptycell(myboard, 4);
    }
    
    drawBoard();
}

void QGameBoard::doCalc()
{
    qDebug() << gamescore;
    emptycell(myboard, 4);

    if (emptypos.empty() && !checkmove(myboard, 4))
    {
        //qDebug() << "reset?";
        resetGame();        //?? or is it?
    }
    
    
    emptycell(myboard, 4);
    score->setText(QString("SCORE: %1").arg(gamescore));
    //drawBoard();
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
    //delete &gameOverWindow;

    QGameOverWindow* gow = new QGameOverWindow();
    gow->show();

    //gameOverWindow.show();
    this->hide();
    //drawBoard();
    score->setText(QString("SCORE: %1").arg(gamescore));
    
    //gameOverWindow.hide();
    
}
