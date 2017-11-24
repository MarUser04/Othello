#include "menu.h"

#include <QDebug>
#include "tablerografico.h"
#include "ficha.h"
#include <QRegion>

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    scene= new QGraphicsScene();
    vistaMenu= new QGraphicsView();
    sceneCreditos= new QGraphicsScene();
    vistaCreditos= new QGraphicsView();


    dosJugadores= new QPushButton("2 Jugadores");
    jugarIA= new QPushButton("Jugar contra la PC");
    creditos= new QPushButton("Creditos");
    retornarMenuB= new QPushButton("Ir al Menu");
    retornarMenuB2= new QPushButton("Ir al Menu");

    nivel1= new QPushButton("Principiante");
    nivel2= new QPushButton("Normal");
    nivel3= new QPushButton("Avanzado");


        QFont serifFont("Times",10,QFont::Bold);

    QGraphicsTextItem* titulo= new QGraphicsTextItem();

    vistaMenu->setFixedSize(450,280);

    QString p="OTHELLO";
    titulo->setPlainText(p);
    scene->addItem(titulo);
    titulo->setPos(115, 50);
    titulo->setScale(2);
    titulo->setDefaultTextColor(QColor(0,0,0));
    titulo->setFont(serifFont);

    scene->addWidget(dosJugadores);
    dosJugadores->move(130,100);
    dosJugadores->setFont(serifFont);
    dosJugadores->setStyleSheet("* { background-color: rgb(255,255,255); "
                                "padding: 10px;  "
                                "border: 1px solid black; "
                                "}");


    dosJugadores->setCursor(Qt::PointingHandCursor);

    scene->addWidget(creditos);
    creditos->move(142,200);
    creditos->setFont(serifFont);
    creditos->setStyleSheet("* { background-color: rgb(255,255,255); "
                                "padding: 10px;  "
                                "border: 1px solid black; "
                                "}");
    creditos->setCursor(Qt::PointingHandCursor);

    scene->addWidget(jugarIA);
    jugarIA->move(112,150);
    jugarIA->setFont(serifFont);
    jugarIA->setStyleSheet("* { background-color: rgb(255,255,255); "
                                "padding: 10px;  "
                                "border: 1px solid black; "
                                "}");

    jugarIA->setCursor(Qt::PointingHandCursor);

    connect(dosJugadores, SIGNAL (clicked()), this, SLOT (jugar()));
    connect(jugarIA, SIGNAL (clicked()), this, SLOT (jugarVsIA()));
    connect(creditos, SIGNAL (clicked()), this, SLOT (creditosMuestra()));
    connect(retornarMenuB, SIGNAL (clicked()), this, SLOT (retornarMenu()));
    connect(retornarMenuB2, SIGNAL (clicked()), this, SLOT (retornarMenu2()));

    connect(nivel1, SIGNAL (clicked()), this, SLOT (principiante()));
    connect(nivel2, SIGNAL (clicked()), this, SLOT (normal()));
    connect(nivel3, SIGNAL (clicked()), this, SLOT (avanzado()));

    QPixmap *pim= new QPixmap();

   //pim->load("C:/Users/Marco/Documents/Programacion/ProyectoEstucturas/OthelloVF1/OthelliIA/OthelloConMenu/ModeloOthello3/ModeloOthello3/images/fondoMenu.jpg");
    pim->load("./images/fondoMenu.jpg");
    scene->setBackgroundBrush(pim->scaled(400,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //QBrush fondoColor(QColor(201,255,234));
    //scene->setBackgroundBrush(fondoColor);


    vistaMenu->setScene(scene);





}

void Menu::show()
{

    vistaMenu->show();
}



void Menu::jugar()
{
        vistaMenu->close();
        vistaJuego= new QGraphicsView();

        TableroGrafico *tablero= new TableroGrafico(1);

        tablero->pintar();
        vistaJuego->setScene(tablero);
        vistaJuego->setFixedSize(750,650);
        vistaJuego->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
       // this->clear();
        vistaJuego->show();


}

void Menu::jugarVsIA()
{
     vistaMenu->close();

     menuOpciones= new QGraphicsView();
     sceneOpciones= new QGraphicsScene();
     sceneOpciones->addWidget(retornarMenuB2);
     retornarMenuB2->move(145,240);
     QFont serifFont("Times",10,QFont::Bold);
     retornarMenuB2->setFont(serifFont);
     retornarMenuB2->setStyleSheet("* { background-color: rgb(255,255,255); "
                                 "padding: 10px;  "
                                 "border: 1px solid black; "
                                 "}");

     retornarMenuB2->setCursor(Qt::PointingHandCursor);


     QGraphicsTextItem* opciones= new QGraphicsTextItem();


     QString p="Eliga su dificultad";
     opciones->setPlainText(p);
     sceneOpciones->addItem(opciones);
     opciones->setPos(100, 50);
     opciones->setScale(1.5);
     opciones->setDefaultTextColor(QColor(255,255,255));
     opciones->setFont(serifFont);



     sceneOpciones->addWidget(nivel1);
     nivel1->move(140,90);
     nivel1->setFont(serifFont);
     nivel1->setStyleSheet("* { background-color: rgb(255,255,255); "
                                 "padding: 10px;  "
                                 "border: 1px solid black; "
                                 "}");

     nivel1->setCursor(Qt::PointingHandCursor);

     sceneOpciones->addWidget(nivel2);

     nivel2->move(150,140);
     nivel2->setFont(serifFont);
     nivel2->setStyleSheet("* { background-color: rgb(255,255,255); "
                                 "padding: 10px;  "
                                 "border: 1px solid black; "
                                 "}");

     nivel2->setCursor(Qt::PointingHandCursor);
     sceneOpciones->addWidget(nivel3);
     nivel3->move(145,190);
     nivel3->setFont(serifFont);
     nivel3->setStyleSheet("* { background-color: rgb(255,255,255); "
                                 "padding: 10px;  "
                                 "border: 1px solid black; "
                                 "}");

     nivel3->setCursor(Qt::PointingHandCursor);


    //QPixmap pim("C:/Users/Marco/Documents/Programacion/ProyectoEstucturas/OthelloVF1/OthelliIA/OthelloConMenu/ModeloOthello3/ModeloOthello3/images/fondoMenu2.jpg");
     QPixmap pim("./images/fondoMenu2.jpg");
     sceneOpciones->setBackgroundBrush(pim.scaled(400,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

 //    QBrush fondoColor(QColor(56,255,222));
 //    sceneCreditos->setBackgroundBrush(fondoColor);

     menuOpciones->setScene(sceneOpciones);
     menuOpciones->setFixedSize(300,250);
     menuOpciones->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
     menuOpciones->show();
}

void Menu::creditosMuestra()
{

    vistaMenu->close();
    vistaCreditos= new QGraphicsView();

    sceneCreditos->addWidget(retornarMenuB);
    retornarMenuB->move(225,240);
    QFont serifFont("Times",10,QFont::Bold);
    retornarMenuB->setFont(serifFont);
    retornarMenuB->setStyleSheet("* { background-color: rgb(255,255,255); "
                                "padding: 10px;  "
                                "border: 1px solid black; "
                                "}");

    retornarMenuB->setCursor(Qt::PointingHandCursor);
    QGraphicsTextItem* creditosTitulo= new QGraphicsTextItem();
    QGraphicsTextItem* marco= new QGraphicsTextItem();
    QGraphicsTextItem* javier= new QGraphicsTextItem();

    QString p="Creditos";
    creditosTitulo->setPlainText(p);
    sceneCreditos->addItem(creditosTitulo);
    creditosTitulo->setPos(200, 50);
    creditosTitulo->setScale(2.5);
    creditosTitulo->setDefaultTextColor(QColor(255,255,255));
    creditosTitulo->setFont(serifFont);


     p="Marco Useche";
    marco->setPlainText(p);
    sceneCreditos->addItem(marco);
    marco->setPos(150, 110);
    marco->setScale(2.5);
    marco->setDefaultTextColor(QColor(255,255,255));
    marco->setFont(serifFont);

     p="Javier Cabello";
    javier->setPlainText(p);
    sceneCreditos->addItem(javier);
    javier->setPos(150, 160);
    javier->setScale(2.5);
    javier->setDefaultTextColor(QColor(255,255,255));
    javier->setFont(serifFont);


    //QPixmap pim("C:/Users/Marco/Documents/Programacion/ProyectoEstucturas/OthelloVF1/OthelliIA/OthelloConMenu/ModeloOthello3/ModeloOthello3/images/fondoMenu2.jpg");
    QPixmap pim("./images/fondoMenu2.jpg");
    sceneCreditos->setBackgroundBrush(pim.scaled(400,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

//    QBrush fondoColor(QColor(56,255,222));
//    sceneCreditos->setBackgroundBrush(fondoColor);

    vistaCreditos->setScene(sceneCreditos);
    vistaCreditos->setFixedSize(300,250);
    vistaCreditos->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    vistaCreditos->show();


}

void Menu::retornarMenu()
{
    vistaCreditos->close();
    Menu *menu= new Menu();
    menu->show();
}

void Menu::retornarMenu2()
{
    menuOpciones->close();
    Menu *menu= new Menu();
    menu->show();
}

void Menu::principiante()
{
    menuOpciones->close();
    vistaJuego= new QGraphicsView();

    TableroGrafico* tablero= new TableroGrafico(2,0);
    tablero->pintar();
    vistaJuego->setScene(tablero);
    vistaJuego->setFixedSize(750,650);
    vistaJuego->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    vistaJuego->show();
}

void Menu::normal()
{
    menuOpciones->close();
    vistaJuego= new QGraphicsView();

    TableroGrafico* tablero= new TableroGrafico(2,1);
    tablero->pintar();
    vistaJuego->setScene(tablero);
    vistaJuego->setFixedSize(750,650);
    vistaJuego->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    vistaJuego->show();

}

void Menu::avanzado()
{

    menuOpciones->close();
    vistaJuego= new QGraphicsView();

    TableroGrafico* tablero= new TableroGrafico(2,2);
    tablero->pintar();
    vistaJuego->setScene(tablero);
    vistaJuego->setFixedSize(750,650);
    vistaJuego->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    vistaJuego->show();
}
