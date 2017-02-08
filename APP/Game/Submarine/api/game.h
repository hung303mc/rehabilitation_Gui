#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <QGraphicsView>
#include "score.h"
#include "health.h"
#include <QTimer>
#include <QDialog>
#include "Serial.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    QGraphicsScene * scene;
    QGraphicsScene * scene2;
    QGraphicsScene * sceneStart;
    Player * player;
    Score *score;
    Health * health;
    int StateCollide;
    QTimer * timerEnemy;
    QTimer * timerOver;
    QTimer * timerTest;
    Serial * myserial;

public slots:
    void gameStart();
    void gameOver();
    void mybuttonClick1();
    void mybuttonClick2();
    void mybuttonClick3();
    void mybuttonClick4();
    void mybuttonClick5();
    void mybuttonClick6();

private:
};

#endif // GAME_H
