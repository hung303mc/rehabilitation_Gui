#include "health.h"
#include <QFont>

/*
    Init score
    Draw the text+color
*/

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){
    // Init score
    health = 3;

    // Draw the text
    setPlainText(QString("Health ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}


int Health::getHealth(){
    return health;
}
