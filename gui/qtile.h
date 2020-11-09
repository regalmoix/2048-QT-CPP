#ifndef QTILE_H
#define QTILE_H

#include <QLabel>

class QTile : public QLabel
{
    Q_OBJECT
    
    public:
        QTile(int x);
        void draw();

    private:
        int val;

};

#endif // QTILE_H
