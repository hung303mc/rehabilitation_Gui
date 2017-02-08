#include <QGraphicsRectItem>
#include "friend.h"
#include <QTimer>
#include <QGraphicsScene>
#include "score.h"
#include "game.h"
#include <QList> // detect colide
#include <typeinfo>

/*
    Constructor: set random position, draw rect, connect(timer -> move())
    Move(): set position
*/

extern Game * game;

Friend::Friend(QGraphicsItem *parent):QObject(), QGraphicsRectItem(parent){
    // draw the rectangle
    setRect(0,0,50,200);
    hide();
    // connect timer to move()
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Friend::move()
{
    // set position
    setPos(x()-5,y());
    // If player meet Friend -> score ++
    QList<QGraphicsItem *> collide_item = collidingItems();
    for(int i=0, n= collide_item.size(); i<n;i++){

        if(typeid(* collide_item[i]) == typeid(Player)){
            //Decrease the health
            game->score->increase();
            // Remove enemy
            scene()->removeItem(this);
            // Delete enemy
            delete this;
            return;
        }
    }
}

