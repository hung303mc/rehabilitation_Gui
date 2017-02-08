#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

static const QString path = "/home/hung303mc/JRDProject/SideScrollerGame/JRD";


class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent *event);
private:
public slots:
    void spawn();
    void test();
};


#endif // PLAYER_H
