#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "enemy.h"
#include <stdlib.h>
#include "friend.h"
#include "game.h"
#include "datalog.h"


extern Game * game;

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    // draw a player
    setPixmap(QPixmap(":/image/player1.png"));
}

void Player::updatePos()
{
    int y_player = game->myserial->serialValue/10;
    if(y_player > 100)y_player = 100;
    y_player = 410-y_player*410/100;
    game->player->setPos(game->player->x(),y_player);
//    qDebug()<<y_player;
}
