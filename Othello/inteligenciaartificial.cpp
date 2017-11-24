#include "inteligenciaartificial.h"
#include <iostream>

using namespace std;
InteligenciaArtificial::InteligenciaArtificial(int dificultad,int jugador, int enemigo)
{
    this->actual= new Tablero();
    this->jugador=jugador;//Por default 2, por si en algun momento queremos cambiarlo no cambiarlo en todo si no solo aqui
    this->enemigo=enemigo; // 1 por default
    this->puntaje=0;
    this->nivel=dificultad;
}

int InteligenciaArtificial::calcular(Tablero *obj /*int &x, int &y*/)//Coordenadas de la mejor jugada
{
//    actual->copiar(obj);
//    actual->imprimirTablero();
//    if(actual==NULL) return;
    Tablero *aux2 = new Tablero();
    aux2->copiar(obj);
//    int puntaje = aux2->puntajeActual(jugador);
//    puntaje=aux2->puntajeActual(jugador);//Puntaje actual de la computara

    int i,k,puntajeInicial=0,minimos=0;
    int maximo=-99999;
//    x=-1;y=-1;//Para verificar errores
    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){
        Tablero *aux= new Tablero();
        aux->copiar(aux2);
        if(aux2->jugable(this->jugador,i,k)){//Jugadas posibles por la computadora
        aux->copiar(aux2);
//        cout<<"TABLERO AUX";
//        aux->imprimirTablero();
//        system("PAUSE");
        aux->jugar(jugador,i,k);
//        cout<<endl<<" TABLERO DE AUX --------"<<endl;
//        aux->imprimirTablero();
//        cout<<endl<<"TABLERO DE ACTUAL -----------"<<endl;
//        actual->imprimirTablero();
        puntajeInicial=aux->puntajeActual(jugador);
        minimos=contrario(aux,puntajeInicial);
//        cout<<endl<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<minimos;
        if(maximo<minimos){//Mejor Jugada
        maximo=minimos;
//        y=i;
//        x=k;
        //cout<<endl;
//        cout<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<maximo;
        }
        }

        }
    }
    return maximo;
//    cout<<endl<<"MAXIMO ELEGIDO "<<maximo<<endl;

}

int InteligenciaArtificial::contrario(Tablero *obj, int puntajeInicial)//Luego de la computadora jugar, las jugadas posibles del jugador
{
    int i,k,puntajeFinal;
    Tablero *aux= new Tablero();
    aux->copiar(obj);
//    cout<<endl<<"DENTRO DEL CONTRARIO "<<endl;
//    aux->imprimirTablero();

    int fichasGanadas=puntajeInicial-this->puntaje;
    int fichasPerdidas;
    int minimo=99999;

    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){

        if(obj->jugable(this->enemigo,i,k)){//Jugadas posibles por el enemigo
        aux->copiar(obj);
        aux->jugar(enemigo,i,k);
//        cout<<endl<<"DENTRO DE CONTRARIO ---------------- LUEGO DE JUGAR"<<endl;
//        aux->imprimirTablero();
//        obj->imprimirTablero();
        puntajeFinal=aux->puntajeActual(jugador);//Puntaje luego de que juegue la persona
        fichasPerdidas=puntajeInicial-puntajeFinal;
//        cout<<endl;
//        cout<<" DENTRO DE CONTARIO MINIMOS "<<fichasGanadas-fichasPerdidas;
        if(minimo> (fichasGanadas-fichasPerdidas) ){
            minimo=fichasGanadas-fichasPerdidas;
//            cout<<endl;
//            cout<<" DENTRO DE contario FICHAS GANADAS "<<fichasGanadas<<" FICHAS PERDIDAS "<<fichasPerdidas<<" MINIMO "<<minimo;
        }

        }

        }
    }
    delete aux;
//    cout<<endl<<" MINIMO ELEGIDO: "<<minimo<<endl;
    return minimo;
}

void InteligenciaArtificial::jugar(Tablero *obj, int &x, int &y)
{
    actual->copiar(obj);
    this->x=-1;
    this->y=-1;
    this->puntaje=this->actual->puntajeActual(jugador);//Puntaje actual de la computara
    switch (this->nivel) {
    case 0://Nivel principiante
        this->principiante();
        break;
    case 1://Nivel intermedio
        this->intermedio();
        break;
    case 2://Nivel Avanzado
        this->avanzado();
        break;
    default:
        cout<<"ERROR: Al seleccionar nivel."<<endl;
        this->x=-1;
        this->y=-1;
        break;
    }
    x=this->x;
    y=this->y;
}

void InteligenciaArtificial::principiante()
{
    int i,k,puntajeFinal=0,valores=0;
    int maximo=-99999;
//    x=-1;y=-1;//Para verificar errores
    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){
        Tablero *aux= new Tablero();
        aux->copiar(this->actual);
        if(this->actual->jugable(this->jugador,i,k)){//Jugadas posibles por la computadora
        aux->copiar(this->actual);
//        cout<<"TABLERO AUX";
//        aux->imprimirTablero();
//        system("PAUSE");
        aux->jugar(jugador,i,k);
//        cout<<endl<<" TABLERO DE AUX --------"<<endl;
//        aux->imprimirTablero();
//        cout<<endl<<"TABLERO DE ACTUAL -----------"<<endl;
//        actual->imprimirTablero();
        puntajeFinal=aux->puntajeActual(jugador);
        valores=puntajeFinal-this->puntaje;
//        minimos=contrario(aux,puntajeInicial);
//        cout<<endl<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<minimos;
        if(maximo<valores){//Mejor Jugada
        maximo=valores;
        this->y=i;
        this->x=k;
        //cout<<endl;
//        cout<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<maximo;
        }
        }

        }
    }
}

void InteligenciaArtificial::intermedio()
{
    int i,k,puntajeInicial=0,minimos=0;
    int maximo=-99999;
//    x=-1;y=-1;//Para verificar errores
    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){
        Tablero *aux= new Tablero();
        aux->copiar(this->actual);
        if(this->actual->jugable(this->jugador,i,k)){//Jugadas posibles por la computadora
        aux->copiar(this->actual);
//        cout<<"TABLERO AUX";
//        aux->imprimirTablero();
//        system("PAUSE");
        aux->jugar(jugador,i,k);
//        cout<<endl<<" TABLERO DE AUX --------"<<endl;
//        aux->imprimirTablero();
//        cout<<endl<<"TABLERO DE ACTUAL -----------"<<endl;
//        actual->imprimirTablero();
        puntajeInicial=aux->puntajeActual(jugador);
        minimos=contrario(aux,puntajeInicial);
//        cout<<endl<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<minimos;
        if(maximo<minimos){//Mejor Jugada
        maximo=minimos;
        y=i;
        x=k;
        //cout<<endl;
//        cout<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<maximo;
        }
        }

        }
    }
}

void InteligenciaArtificial::avanzado()
{
    int i,k,puntajeInicial=0,minimos=0;
    int maximo=-99999;\
    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){
        Tablero *aux= new Tablero();
        aux->copiar(this->actual);
        if(this->actual->jugable(this->jugador,i,k)){//Jugadas posibles por la computadora
        aux->copiar(this->actual);
        aux->jugar(jugador,i,k);
        puntajeInicial=aux->puntajeActual(jugador);
        minimos=contrario2(aux,puntajeInicial);
        if(maximo<minimos){//Mejor Jugada
        maximo=minimos;
        y=i;
        x=k;
        //cout<<endl;
//        cout<<" DENTRO DE CALCULAR X-> "<<x<<" Y-> "<<y<<" MAXIMOS= "<<maximo;
        }
        }

        }
    }
}

int InteligenciaArtificial::contrario2(Tablero *obj, int puntajeInicial)//Luego de la computadora jugar, las jugadas posibles del jugador
{
    int i,k,puntajeFinal;
    Tablero *aux= new Tablero();
    aux->copiar(obj);
//    cout<<endl<<"DENTRO DEL CONTRARIO "<<endl;
//    aux->imprimirTablero();

    int fichasGanadas=puntajeInicial-this->puntaje;
    int fichasPerdidas;
    int minimo=99999;
    int maximos2=0;
    for( i= 0; i<8; i++){
        for( k=0; k<8; k++){

        if(obj->jugable(this->enemigo,i,k)){//Jugadas posibles por el enemigo
        aux->copiar(obj);
        aux->jugar(enemigo,i,k);
//        cout<<endl<<"DENTRO DE CONTRARIO ---------------- LUEGO DE JUGAR"<<endl;
//        aux->imprimirTablero();
//        obj->imprimirTablero();

        maximos2=this->calcular(obj);


        puntajeFinal=aux->puntajeActual(jugador);//Puntaje luego de que juegue la persona
        fichasPerdidas=puntajeInicial-puntajeFinal;
//        cout<<endl;
//        cout<<" DENTRO DE CONTARIO MINIMOS "<<fichasGanadas-fichasPerdidas;
        if(minimo> maximos2/*(fichasGanadas-fichasPerdidas)*/ ){
            minimo=fichasGanadas-fichasPerdidas;
//            cout<<endl;
//            cout<<" DENTRO DE contario FICHAS GANADAS "<<fichasGanadas<<" FICHAS PERDIDAS "<<fichasPerdidas<<" MINIMO "<<minimo;
        }

        }

        }
    }
    delete aux;
//    cout<<endl<<" MINIMO ELEGIDO: "<<minimo<<endl;
    return minimo;
}
