#ifndef FRIEND_H
#define FRIEND_H

#include <QGraphicsRectItem>
#include <QObject>

class Friend: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Friend(QGraphicsItem * parent = 0);
public slots:
    void move();
};
#endif // FRIEND_H
