#include <QGraphicsRectItem>
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "health.h"
#include "game.h"
#include <QList> // detect colide
#include <typeinfo>

/*
    Constructor: set random position, draw rect, connect(timer -> move())
    Move(): set position
*/

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // draw the rectangle
    setPixmap(QPixmap(":/image/enemy.png"));


    // connect timer to move()
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // set position
    setPos(x()-5,y());
    // if bullet collide enemy, destroy both

    QList<QGraphicsItem *> collide_item = collidingItems();
    for(int i=0, n= collide_item.size(); i<n;i++){

        if(typeid(* collide_item[i]) == typeid(Player)){
            //Decrease the health
            game->health->decrease();
            // Remove enemy
            scene()->removeItem(this);
            // Delete enemy
            delete this;
            return;
        }
    }
}

