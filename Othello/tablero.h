#ifndef TABLERO_H
#define TABLERO_H
#include "ficha.h"

class Tablero
{
    Ficha *matriz[8][8];
public:
    Tablero();
    void imprimirTablero();
    bool jugar(int jugador, int i, int k);
    void cambiar(int jugador, int i, int k);
    bool jugable(int jugador, int i, int k);//Determina si esa ficha es jugable para el jugador actual ( Parametro: jugador)
    void inicializar();//Inicializa el tablero
    int puntajeActual(int jugador);
    Ficha* getFicha(int i, int k);
    void copiar(Tablero* obj);
    void calcularPistas(int jugador);
    void vaciarPistas();
};

#endif // TABLERO_H
