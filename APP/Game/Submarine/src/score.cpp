#include "score.h"
#include <QFont>

/*
    Init score
    Draw the text+color
*/

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    // Init score
    score = 0;

    // Draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore(){
    return score;
}
