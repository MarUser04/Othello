#ifndef INTELIGENCIAARTIFICIAL_H
#define INTELIGENCIAARTIFICIAL_H

#include "tablero.h"
//#include "ListaSimpleEnlazada.h"
class InteligenciaArtificial
{
    Tablero *actual;
    int jugador;//Que jugador es la computadora
    int enemigo;//Que jugador es la persona
    int puntaje;
    int nivel;// 0 = principiante ------ 1 = intermedio ----- 2 = avanzado
    int x;//Posicion en equis donde jugara
    int y;//Posicion en y donde jugara
//    ListaSimpleEnlazada<int> listaMax;
public:
    InteligenciaArtificial(int dificultad=1, int jugador=2, int enemigo=1);
    int calcular(Tablero *obj);
    int contrario(Tablero *obj, int puntajeInicial);
    int contrario2(Tablero *obj, int puntajeInicial);
    void jugar(Tablero *obj, int &x, int &y);
    void principiante();
    void intermedio();
    void avanzado();
};

#endif // INTELIGENCIA
