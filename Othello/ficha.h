#ifndef FICHA_H
#define FICHA_H


class Ficha
{
    int id;
    bool jugada;// Indica si la casilla ha sido jugada o esta vacia
    int jugador;//Que jugador esta en es casilla 1 = "X" ------ 2 = "O" ----- 0 = VACIA
public:
    Ficha(int id, bool jugada=false);
    int getId();
    void setId(int value);
    bool getJugada();
    void setJugada(bool value);
    void cambiar(int jugador);
    void imprimir();
    int getJugador();
    void setJugador(int value);
    void copiar(Ficha *obj);
};

#endif // FICHA_H
