#include "gui/qgameboard.h"
#include "gui/qtile.h"

#include <QTestEventList>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QApplication>


#include <core/global.h>

QGameBoard::~QGameBoard()
{
    //delete game;
}

QGameBoard::QGameBoard(QWidget *parent) : QWidget(parent)
{
    // Set Size of Board
    resize(520,520);


    over = 0;

    // Create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    //boardLayout = NULL;

    
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
        }
    }

    

    drawBoard();

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(gamescore));

    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    //score->setStyleSheet("QLabel { color: rgb(255, 189, 230); font: 16pt; }");
    //score->setStyleSheet("QLabel { background-color: rgb(255, 189, 230); border-radius: 10px; font: bold; color: white; }");
    
    score->setFixedHeight(50);
    //score->setFixedWidth(200);

    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    //connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
    //QThread::sleep(10);

    //QKeyEvent *event = new QKeyEvent (QEvent::KeyPress, Qt::Key_Left);
    //postEvent (QGameBoard::keyPressEvent, event);
    /*
    int num_moves = 5;
    while (num_moves--)
    {
        QThread::sleep(1);
        QKeyEvent *key_press = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Up, Qt::NoModifier, "x");
        QApplication::sendEvent(this, key_press);
    }

    */
    
}


// Currently Only Prints to console
void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    auto old_board = myboard;
    
    qDebug() << "Key Press";
    
    switch (event->key()) 
    {
        case Qt::Key_Up:
            qDebug() << "Key Up";

            up(myboard, 4);
            doCalc();
            break;

        case Qt::Key_Left:
            qDebug() << "Key L";
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

    srand(time(0));
    int mv = rand() % 4;
    
    Qt::Key KP;

    switch (mv)
    {
        case 0 :    KP = Qt::Key_Left;
                    break;
        case 1 :    KP = Qt::Key_Right;
                    break;
        case 2 :    KP = Qt::Key_Up;
                    break;
        case 3 :    KP = Qt::Key_Down;
                    break;
    }
    QTestEventList eve;

    if (over == 0)
    {
        qDebug() << "Here";
        
        eve.addKeyPress(KP, Qt::NoModifier, 1000);
        //eve.addDelay(3000);
        eve.simulate(this);
    }

    else if (over == 1)
    {
        qDebug() << "1 Here";
        eve.clear();
    }
    
    /*
        if (num > 0)
        {
            num --;
            drawBoard();
            QThread::sleep(2);
            QKeyEvent *key_press = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Left, Qt::NoModifier, "x");
            QApplication::sendEvent(this, key_press);
            qDebug << "Test";
            drawBoard();
        }
    
    */
    //drawBoard();
        
}

void QGameBoard::doCalc()
{
    //qDebug() << gamescore;
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

    qDebug() << "Draw";

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
    over = 1;

    QGameOverWindow* gow = new QGameOverWindow();
    gow->show();

    //gameOverWindow.show();
    this->close();
    //drawBoard();
    score->setText(QString("SCORE: %1").arg(gamescore));
    
    //gameOverWindow.hide();
    // exit(0);
    
}
