#include "tablerografico.h"
#include "ficha.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <QPainter>
#include <QCursor>
#include <QHoverEvent>
#include <QGraphicsSceneHoverEvent>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include <windows.h>
#include <string>
#include "score.h"
#include <QPixmap>
#include "inteligenciaartificial.h"
#include "tablero.h"
#include "menu.h"

using namespace std;

int TableroGrafico::getTamFicha() const
{
    return tamFicha;
}

void TableroGrafico::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    this->click = true;
}

void TableroGrafico:: mouseReleaseEvent(QGraphicsSceneMouseEvent *ev) {


    int xi=0, yi=0;

    if (ev->scenePos().x() <= 64*8 && ev->scenePos().x()>=0) {
        if (ev->scenePos().y() <= 64*8 && ev->scenePos().y()>=0) {

            if(!juego->getFinalizado()){
            if(this->modo==1){
                juego->jugar(ev->scenePos().y()/64, ev->scenePos().x()/64);
                this->x = ev->scenePos().x()/64;
                this->y = ev->scenePos().y()/64;

                this->pintar();

                QGraphicsScene::mouseReleaseEvent(ev);
            }
            else{


                     juego->jugar(ev->scenePos().y()/64, ev->scenePos().x()/64);
                      this->pintar();

                     if(!juego->getTurno()){
                     Tablero *aux =juego->getTablero();
                     computadora->jugar(aux, xi,yi);
                     cout<<"X: "<< xi <<endl;
                     cout<<"Y: "<< yi <<endl;
                     juego->jugar(yi,xi);
                     }

                this->pintar();
                QGraphicsScene::mouseReleaseEvent(ev);
            }
            }else {
                this->pintar();


                }

            if(juego->getFinalizado()){
                this->pintar();

            }
        }
    }


    this->click = false;

}


void TableroGrafico::SugerenciaIA(){
    int xi=-1,yi=-1;
    if(this->modo==2){//Un jugador

        InteligenciaArtificial *aux = new InteligenciaArtificial(2,1,2);//Dos pa que piense bastante y lo otro para que sea inverso al normal
        Tablero *tabla =juego->getTablero();
        aux->jugar(tabla,xi,yi);
        //Metodo nuevo que seria como el de pintarSugerencia pero seria en vez de eso una ficha de diferente color y ya
        PintarSugerencia(xi,yi);
    }else{//Dos jugadoras
        int ene,jug;
        if(!juego->getTurno()){
        ene=1;
        jug=2;
        }else{
        ene=2;
        jug=1;
        }
        InteligenciaArtificial *aux = new InteligenciaArtificial(2,jug,ene);//Dos pa que piense bastante y lo otro para que sea inverso al normal
        Tablero *tabla =juego->getTablero();
        aux->jugar(tabla,xi,yi);
//Metodo nuevo que seria como el de pintarSugerencia pero seria en vez de pintar el cuadrado seria pintar una ficha de diferente color y ya
        PintarSugerencia(xi,yi);
        //juego->CambioTurno();
    }
}

void TableroGrafico::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Escape )
     {
         this->deleteLater();

         Menu* menu= new Menu();
         menu->show();
    }
    else if( event->key() == Qt::Key_Space){

        SugerenciaIA();
    }
}

void TableroGrafico::PintarResultado()
{
    ganador1= new QGraphicsTextItem();
    ganador2= new QGraphicsTextItem();
    empate= new QGraphicsTextItem();

     QFont serifFont("Times",10,QFont::Bold);
    if(juego->ganador()==1){

        QString text="Ganó Jugador 1! \nFelicidades.";
        ganador1->setPlainText(text);


        QString text2="Jugador 2,\nmás suerte la práxima";
        ganador2->setPlainText(text2);

        empate->hide();


    }else  if(juego->ganador()==2){

        QString text="Gano Jugador 2! \nFelicidades.";
        ganador2->setPlainText(text);


        QString text2="Jugador 1,\n más suerte la práxima";
        ganador1->setPlainText(text2);

         empate->hide();

    }
    else if(juego->ganador()==3){

         QString text="Es un empate!";
         empate->setPlainText(text);
        ganador1->hide();
        ganador2->hide();
    }

    this->addItem(ganador1);
    ganador1->setPos(530, 330);
    ganador1->setScale(1.4);
    ganador1->setDefaultTextColor(QColor(0,0,0));
    ganador1->setFont(serifFont);

    this->addItem(ganador2);
    ganador2->setPos(530, 380);
    ganador2->setScale(1.4);
    ganador2->setDefaultTextColor(QColor(255,255,255));
    ganador2->setFont(serifFont);
    this->addItem(empate);
    empate->setPos(530, 330);
    empate->setScale(1.4);
    empate->setDefaultTextColor(QColor(0,0,0));
    empate->setFont(serifFont);



}


int TableroGrafico::getCoordX() const
{
    return coordX;
}

int TableroGrafico::getCoordY() const
{
    return coordY;
}

int TableroGrafico::getContNegras() const
{
    return contNegras;
}

int TableroGrafico::getContBlancas() const
{
    return contBlancas;
}



TableroGrafico::TableroGrafico(int modo,int nivel,QObject *parent) : QGraphicsScene(parent)
{
    computadora= new InteligenciaArtificial(nivel);
    this->modo=modo;

    QPixmap pim("./images/bamboo.jpg");
    this->setBackgroundBrush(pim.scaled(720,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}

TableroGrafico::~TableroGrafico()
{

}

int TableroGrafico::getY() const
{
    return y;
}

void TableroGrafico::setY(int value)
{
    y = value;
}

void TableroGrafico::pintar()
{
    this->clear();

    puntN= new Score();
    puntB= new Score();
    titulo= new QGraphicsTextItem();
    puntajes= new QGraphicsTextItem();
    turno= new QGraphicsTextItem();
    escape= new QGraphicsTextItem();
    espacio= new QGraphicsTextItem();

    this->PintarFondo();

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
           if(juego->getTablero()->getFicha(i,j)->getJugada())
                this->PintarFicha(juego->getTablero()->getFicha(i,j)->getJugador(), i,j);


        }
    }

    QFont serifFont("Times",10,QFont::Bold);

    QString ti="OTHELLO";
    titulo->setPlainText(ti);
    this->addItem(titulo);
    titulo->setPos(530, 50);
    titulo->setScale(2.5);
    titulo->setDefaultTextColor(QColor(0,0,0));
    titulo->setFont(serifFont);

    QString p="Puntajes";
    puntajes->setPlainText(p);
    this->addItem(puntajes);
    puntajes->setPos(530, 100);
    puntajes->setScale(2.5);
    puntajes->setDefaultTextColor(QColor(0,0,0));
    puntajes->setFont(serifFont);

    char* negras= "Negras: ";
    char* blancas= "Blancas: ";

    puntN->sumarPuntos(negras,juego->getPuntacionJugador1());
    this->addItem(puntN);
    puntN->setPos(530, 170);
    puntN->setDefaultTextColor(QColor(0,0,0));
    puntN->setScale(2);
    puntN->setFont(serifFont);


    puntB->sumarPuntos(blancas,juego->getPuntacionJugador2());
    this->addItem(puntB);
    puntB->setPos(530, 210);
    puntB->setDefaultTextColor(QColor(255,255,255));
    puntB->setScale(2);
    puntB->setFont(serifFont);


    char *t;
    if(!juego->getTurno())
         t= "Turno: Blancas";
    else
        t="Turno: Negras";


    turno->setPlainText(t);
    this->addItem(turno);
    turno->setPos(530, 250);

    if(!juego->getTurno())
         turno->setDefaultTextColor(QColor(255,255,255));
    else
       turno->setDefaultTextColor(QColor(0,0,0));

    turno->setScale(1.8);
    turno->setFont(serifFont);

    if(juego->getFinalizado())
        this->PintarResultado();

    QString e="Presione Esc \n para regresar al menu";
    escape->setPlainText(e);
    this->addItem(escape);
    escape->setPos(530, 450);
    escape->setScale(1.2);
    escape->setDefaultTextColor(QColor(0,0,0));
    escape->setFont(serifFont);

    QString es="Presione Espacio \n para mostrar uns pista ";
    espacio->setPlainText(es);
    this->addItem(espacio);
    espacio->setPos(530, 500);
    espacio->setScale(1.2);
    espacio->setDefaultTextColor(QColor(0,0,0));
    espacio->setFont(serifFont);



}

void TableroGrafico::PintarFondo()
{

    QBrush fondo(QColor(11,128,124));
    int x = 0, y = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

           this->addRect(x,y,64,64,QPen(Qt::white),fondo);
               x+=64;
        }
        x=0;
        y+=64;
    }


}

void TableroGrafico::PintarFicha(int jugador, int x, int y)
{
    QBrush negroColor(QColor(0,0,0));
    QBrush blancoColor(QColor(255,255,255));
    QBrush grisColor(QColor(218,218,218));

int aux=0;
        if(juego->getTurno())
       aux=1;
        else aux=2;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(juego->getTablero()->jugable(aux,i,j)){

                     this->PintarPista(j, i);
            }
            if(juego->getTablero()->getFicha(i,j)->getJugador()==1){
                this->addEllipse(x+5,y+5,this->tamFicha,this->tamFicha, QPen(Qt::black), negroColor);
            }
            if(juego->getTablero()->getFicha(i,j)->getJugador()==2){
                 this->addEllipse(x+5,y+5,this->tamFicha,this->tamFicha, QPen(Qt::white), blancoColor);
            }

               x+=64;
        }
        x=0;
        y+=64;
    }
}

void TableroGrafico::PintarPista( int x, int y)
{

    QBrush grisColor(QColor(218,218,218));
    this->addRect(x*64,y*64,64,64,QPen(Qt::white),grisColor);


}

void TableroGrafico::PintarSugerencia(int x, int y)
{
    y*=64;
    x*=64;
    QBrush grisColor(QColor(41,128,185));
    this->addEllipse(x+5,y+5,55,55,QPen(Qt::black),grisColor);
}

int TableroGrafico::getX() const
{
    return x;
}

void TableroGrafico::setX(int value)
{
    x = value;
}



