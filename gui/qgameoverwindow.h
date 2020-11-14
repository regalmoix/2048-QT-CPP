#ifndef QGAMEOVERWINDOW_H
#define QGAMEOVERWINDOW_H

#include <QWidget>
#include <QLabel>


class QResetButton;

class QGameOverWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit QGameOverWindow(QWidget *parent = 0);

        //QResetButton* getResetBtn() const;
        QLabel* getSCBtn() const;
        
    private:
        //QResetButton* reset;
        QLabel* SC;


};

#endif // QGAMEOVERWINDOW_H
