#include "game.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QPushButton>
#include <QDialog>
#include "dialog.h"
#include <QLabel>
#include "Serial.h"


/*
    Add scene:  add player into it
    Add player item: make it focusable, set it position
    Add view (display scene): show it, set its size
    Add enemy:
*/
Game::Game()
{
    // add the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,640,480);
    setBackgroundBrush(QBrush(QImage(":/image/bg.png")));
    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,640,480);

    // add view + scene to view
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(640,480);

    /**************
    *   Scene game
    **************/
    // add player item + player to scene
    player = new Player();
    scene->addItem(player);
    // make player focusable 
    player->setFlags(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2 - player->pixmap().width()/2,
                   height()/2 - player->pixmap().height()/2);

    // add score
    score = new Score();
    scene->addItem(score);

    // add health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // spawn enemy
    timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(spawn()));


    // Setting timer for GameOver
    timerOver = new QTimer();
    QObject::connect(timerOver,SIGNAL(timeout()),this,SLOT(gameOver()));

    //add Arduino Serialport
//    arduino = new MySerial();
//    qDebug() <<"serial port: "<< arduino->portName();
//    QObject::connect(arduino,SIGNAL(readyRead()),arduino,SLOT(readSerial()));
    timerTest = new QTimer();
    QObject::connect(timerTest,SIGNAL(timeout()),player,SLOT(test()));

    // add Serial test 2
    myserial = new Serial();

    // play back ground music
//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sound/noemotion.mp3"));
//    music->play();
//    show();
}

void Game::gameStart()
{
    setScene(scene);
    timerEnemy->start(5000);
    //timerOver->start(1000*60);
    timerTest->start(50);
}

void Game::gameOver()
{
    timerEnemy->stop();
    setScene(scene2);
    timerOver->stop();
    timerTest->stop();

    Dialog * DialogOver = new Dialog();
    QLabel * labelOver = new QLabel();
    DialogOver->move(x()+width()/3,y()+height()/3);
    labelOver->setText("Congratulation");
    labelOver->setParent(DialogOver);
    DialogOver->show();
}

void Game::mybuttonClick1()
{
    myserial->sendCommand(1);
}

void Game::mybuttonClick2()
{
    myserial->sendCommand(2);
}

void Game::mybuttonClick3()
{
    myserial->sendCommand(3);
}

void Game::mybuttonClick4()
{
    myserial->sendCommand(4);
}

void Game::mybuttonClick5()
{
myserial->sendCommand(5);
}

void Game::mybuttonClick6()
{
myserial->sendCommand(6);
}
