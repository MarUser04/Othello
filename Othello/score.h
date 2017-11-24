#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <string>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void sumarPuntos(char* name, int puntaje);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
