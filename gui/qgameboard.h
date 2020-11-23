#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "qgameoverwindow.h"
#include "core/global.h"

#include <QVector>
#include <QWidget>
#include <vector>

class QResetButton;
class QKeyEvent;
class QTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;

class QGameBoard : public QWidget
{
    Q_OBJECT
    
    public:
        std::vector<vector<int>> myboard;
        //QVector<QVector<int> > 
        explicit QGameBoard(QWidget *parent = 0);
        void doCalc();
        ~QGameBoard();


    private:

        // gui representation of board
        QVector<QVector<QTile*> > gui_board;
        QVector<QVector<QLabel*> > gui_label;
        // main layout
        QVBoxLayout *mainLayout;
        // grid layout of board
        QGridLayout *boardLayout;
        // score widget
        QLabel *score;
        // game over widget
        //QGameOverWindow gameOverWindow;
        // winner widget
        // QLabel *youwin;
        int over;

        void drawBoard();

    protected:
        void keyPressEvent(QKeyEvent *event);

        
    signals:

    public slots:
        void resetGame();
    

};

#endif // QGAMEBOARD_H
