#ifndef TABLEROGRAFICO_H
#define TABLEROGRAFICO_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "ficha.h"

#include <QDebug>
#include <QHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QPushButton>
#include "inteligenciaartificial.h"
#include "score.h"

#include <QThread>
#include <juego.h>
#include <QObject>

class TableroGrafico : public QGraphicsScene
{
    Q_OBJECT
    private:
        int x, y;
        int cuadrados=80;
        int filasYColumnas = 8;
        int acumCoords[2]={0,0};
        int tamFicha=50;

        bool click;

        int coordX, coordY;
        int contNegras=0, contBlancas=0;
        Score *puntN;
        Score *puntB;
        QGraphicsTextItem *titulo;
        QGraphicsTextItem *puntajes;
        QGraphicsTextItem *turno;
        QGraphicsTextItem *escape;
        QGraphicsTextItem *espacio;

        QGraphicsTextItem *ganador1;
        QGraphicsTextItem *ganador2;
        QGraphicsTextItem *empate;


        Juego *juego= new Juego();

        QPushButton *menu;

         InteligenciaArtificial *computadora;
        int modo;




private slots:
   void retornarMenu();

    public:
        TableroGrafico(int modo,int nivel=2,QObject *parent=0);
        ~TableroGrafico();


        int getX() const;
        void setX(int value);
        int getY() const;
        void setY(int value);
        void pintar();
        void PintarFondo();
        void PintarFicha(int jugador, int x, int y);
        void PintarPista(int x, int y);
        void PintarSugerencia(int x, int y);

        int getTamFicha() const;

        virtual void mousePressEvent(QGraphicsSceneMouseEvent *e );
          virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e );


        virtual void keyPressEvent( QKeyEvent * event );

        void PintarResultado();
        void SugerenciaIA();

        int getCoordX() const;
        int getCoordY() const;

        bool HayMovimientos();
        int getContNegras() const;
        int getContBlancas() const;



        static void sleep(unsigned long usecs){QThread::sleep(usecs);}

};

#endif // TABLERO_H
