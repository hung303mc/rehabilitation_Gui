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
#include "enemy.h"
#include "friend.h"

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
    // add player
    player = new Player();
    scene->addItem(player);
    player->setPos(width()/2 - player->pixmap().width()/2,
                   height()/2 - player->pixmap().height()/2);

    // add score
    score = new Score();
    scene->addItem(score);

    // add health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // connect timer to create Enemy & Friend
    timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),this,SLOT(spawnEnemy()));

    // connect timer to update player
    timerPlayer = new QTimer();
    QObject::connect(timerPlayer,SIGNAL(timeout()),player,SLOT(updatePos()));

    // Setting timer for GameOver
    timerOver = new QTimer();
    QObject::connect(timerOver,SIGNAL(timeout()),this,SLOT(gameOver()));

    // add Serial test
    myserial = new Serial();
}

void Game::gameStart()
{
    setScene(scene);
    timerEnemy->start(5000);
    //timerOver->start(1000*60);
    timerPlayer->start(50);
}

void Game::gameOver()
{
    timerEnemy->stop();
    setScene(scene2);
    timerOver->stop();
    timerPlayer->stop();

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

void Game::spawnEnemy()
{
    // set random position
    int random_number = rand() % 200;
    // Create upper pipe
    Enemy * upperPipe = new Enemy();
    upperPipe->setTransformOriginPoint(upperPipe->pixmap().width()/2, upperPipe->pixmap().height()/2);
    upperPipe->setRotation(180);
    upperPipe->setPos(800,-200+random_number);
    scene->addItem(upperPipe);
    // create lower pipe + add into the scene
    Enemy * lowerPipe = new Enemy();
    lowerPipe->setPos(800,300+random_number);
    scene->addItem(lowerPipe);
    // create friend between 2 pipe + add into the scene
    Friend * betweenSpace = new Friend();
    betweenSpace->setPos(800,100+random_number);
    scene->addItem(betweenSpace);
}
