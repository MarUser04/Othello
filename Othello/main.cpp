
#include <QApplication>
#include <QGraphicsView>

#include <QPoint>
#include <QPainter>
#include <QCursor>
#include <QEvent>

#include "tablerografico.h"
#include "ficha.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <iostream>
#include <conio.h>
#include <QPixmap>
#include "menu.h"
#include <QPushButton>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     Menu *menu= new Menu();
     menu->show();


    return a.exec();
}

