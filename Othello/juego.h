#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"

class Juego
{
    Tablero *tablero;// Tablero de juego
    int PuntacionJugador1;//Puntacion para el jugador 1
    int PuntacionJugador2;//Puntacion para el jugador 2
    bool turno;//Falso = jugador 1 ------ Verdadero = Jugador 2
    bool finalizado=false;
public:
    Juego();
    void jugar(int y,int x);
    void CambioTurno();
    bool fin();
    void calcularPuntos();
    bool getTurno();
    void setTurno(bool value);
    int getPuntacionJugador2();
    void setPuntacionJugador2(int value);
    int getPuntacionJugador1();
    void setPuntacionJugador1(int value);
    bool HayMovimientos(int jugador);
    void imprimir();//Metodo Provisional para imprimir el juego
    Tablero *getTablero();
    void setTablero(Tablero *aux);
    void calcularPistas();
    bool getFinalizado() const;
    void setFinalizado(bool value);
    int ganador();
};

#endif // JUEGO_H
