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
    Score  * score;
    Health * health;
    QTimer * timerEnemy;
    QTimer * timerOver;
    QTimer * timerPlayer;
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
    void spawnEnemy();
private:
};

#endif // GAME_H
