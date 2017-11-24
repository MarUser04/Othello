#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsView>
#include <QMainWindow>


class Menu: public QMainWindow
{
    Q_OBJECT

    QPushButton *dosJugadores;
    QPushButton *jugarIA;
    QPushButton *creditos;
    QPushButton *retornarMenuB;
    QPushButton *retornarMenuB2;
    QPushButton *nivel1;
    QPushButton *nivel2;
    QPushButton *nivel3;


    QGraphicsView* vistaJuego;
    QGraphicsView* vistaMenu;
    QGraphicsScene *scene;

    QGraphicsView* vistaCreditos;
    QGraphicsScene *sceneCreditos;


    QGraphicsView *menuOpciones;
    QGraphicsScene *sceneOpciones;

    public:
        Menu(QWidget *parent=0);
        void show();

    private slots:
       void jugar();
       void jugarVsIA();
       void creditosMuestra();
       void retornarMenu();
       void retornarMenu2();
       void principiante();
       void normal();
       void avanzado();
};

#endif // MENU_H
