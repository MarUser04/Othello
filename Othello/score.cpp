#include "Score.h"
#include <QFont>
#include <string>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    score = 0;

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::sumarPuntos(char* name, int puntaje){

    score=puntaje;
    setPlainText(QString(name) + QString::number(puntaje)); // Score: 1
}

int Score::getScore(){
    return score;
}
