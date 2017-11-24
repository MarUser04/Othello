#include "ficha.h"
#include <iostream>

using namespace std;
int Ficha::getJugador()
{
    return jugador;
}

void Ficha::setJugador(int value)
{
    jugador = value;
}

void Ficha::copiar(Ficha *obj)
{
    obj->setId(this->id);
    obj->setJugada(this->jugada);
    obj->setJugador(this->getJugador());
}


Ficha::Ficha(int id, bool jugada)
{
    this->id=id;
    this->jugada=jugada;
    this->jugador=0;
}

int Ficha::getId()
{
    return id;
}

void Ficha::setId(int value)
{
    id = value;
}

bool Ficha::getJugada()
{
    return jugada;
}

void Ficha::setJugada(bool value)
{
    jugada = value;
}

void Ficha::cambiar(int jugador)
{
    this->jugada=true;
    this->jugador=jugador;
}

void Ficha::imprimir()
{
    if(this->jugada){
        switch (this->jugador) {
        case 1:
            cout<<"X";
            break;
        case 2:
            cout<<"O";
            break;
        default:
            break;
        }
    } else {
        cout<<"1";
    }
}

