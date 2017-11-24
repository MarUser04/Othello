
#include "juego.h"
#include <iostream>
#include "tablero.h"
using namespace std;
bool Juego::getTurno()
{
    return turno;
}

void Juego::setTurno(bool value)
{
    turno = value;
}

int Juego::getPuntacionJugador2()
{
    return PuntacionJugador2;
}

void Juego::setPuntacionJugador2(int value)
{
    PuntacionJugador2 = value;
}

int Juego::getPuntacionJugador1()
{
    return PuntacionJugador1;
}

void Juego::setPuntacionJugador1(int value)
{
    PuntacionJugador1 = value;
}

bool Juego::HayMovimientos(int jugador)
{
    for(int i=0 ; i<8 ; i++){
        for(int k=0; k<8; k++){
        if( this->tablero->jugable(jugador,i,k))
            return true;
        }
    }
    return false;
}

void Juego::imprimir()
{

    calcularPuntos();

}

Tablero *Juego::getTablero()
{
    return tablero;
}

void Juego::setTablero(Tablero *aux)
{
    this->tablero= aux;
}


bool Juego::getFinalizado() const
{
    return finalizado;
}

void Juego::setFinalizado(bool value)
{
    finalizado = value;
}

int Juego::ganador()
{
    if(PuntacionJugador1<PuntacionJugador2){
        cout<<"El ganador es el jugador 2 (Fichas blancas) con "<<PuntacionJugador2<<" Puntos! "<<endl;
        return 2;
    }
    if(PuntacionJugador1>PuntacionJugador2){
        cout<<"El ganador es el jugador 1 (Fichas negras) con "<<PuntacionJugador1<<" Puntos! "<<endl;
        return 1;
    }
    if(PuntacionJugador1==PuntacionJugador2){
        cout<<"Es un empate! Ambos con "<<PuntacionJugador1<<" Puntos! "<<endl;
        return 3;
    }

}


Juego::Juego()
{
    this->tablero = new Tablero();
    this->tablero->inicializar();

    this->PuntacionJugador1 = 0;
    this->PuntacionJugador2 = 0;

this->turno=true;
this->calcularPuntos();


}

void Juego::jugar(int y, int x)//Coordenadas
{

if(turno){

    if(HayMovimientos(1)){//Si hay movimientos posibles para el jugador 1
        if(y>=0 && y<8 && x>=0 && x<8 )
     if(this->tablero->jugar(1,y,x)){
     CambioTurno();
     }
    } else {
        CambioTurno();
        cout<<"PASO TURNO JUGADOR 1 NO MAS MOVIMIENTOS"<<endl;
    }


} else {

    if(HayMovimientos(2)){//Si hay movimientos posibles para el jugador 2
        if(y>=0 && y<8 && x>=0 && x<8 )
     if(this->tablero->jugar(2,y,x)){
     CambioTurno();
     }
    } else {
        CambioTurno();
                cout<<"PASO TURNO JUGADOR 2 NO MAS MOVIMIENTOS"<<endl;
    }
}
this->imprimir();
fin();
}

void Juego::CambioTurno()
{
    this->turno=!turno;
}

bool Juego::fin()
{
    finalizado = !(HayMovimientos(1) || HayMovimientos(2)); //Es el fin, no es posible jugar para ningun jugador
    return finalizado;
}

void Juego::calcularPuntos()
{
this->PuntacionJugador1 = this->tablero->puntajeActual(1);
this->PuntacionJugador2 = this->tablero->puntajeActual(2);
}
