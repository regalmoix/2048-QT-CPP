#include "qgameoverwindow.h"
#include "core/global.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QGameOverWindow::QGameOverWindow(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425,205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;} ");
    
    
    SC = new QLabel("Score ", this);
    qDebug() << "in over " << gamescore;
    SC->setText(QString("Score = %1").arg(gamescore));
    SC->setAlignment(Qt::AlignCenter);
    SC->setStyleSheet("QLabel { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");


    SC->setFixedHeight(80);
    SC->setFixedWidth(150);    


    // add game over label to window
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    
    
    // add score button to window
    layout->insertWidget(1,SC,0,Qt::AlignCenter);
}


QLabel* QGameOverWindow::getSCBtn() const
{
    //return reset;
    return SC;
}