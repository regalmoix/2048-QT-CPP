#ifndef QWINWINDOW_H
#define QWINWINDOW_H

#include <QWidget>

class QWinWindow : public QWidget
{
    Q_OBJECT
    public:
        explicit QWinWindow(QWidget *parent = 0);
};

#endif // QWINWINDOW_H
