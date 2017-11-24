#include "tablero.h"
#include <iostream>

using namespace std;
Tablero::Tablero()
{
    int cont=0;
    for(int i=0;i<8;i++){
        for(int k=0;k<8;k++){
            this->matriz[i][k] = new Ficha(cont);
            cont++;
        }
    }
}

void Tablero::imprimirTablero()
{
    cout<<endl<<endl<<"Tablero actual: "<<endl;
    cout<<"-";
    for(int i=0;i<8;i++)
        cout<<"-"<<i;
    for(int i=0;i<8;i++){
        cout<<endl;
        cout<<i;
        for(int k=0;k<8;k++){
            cout<<"-";
            this->matriz[i][k]->imprimir();

        }
    }
}

bool Tablero::jugar(int jugador, int i, int k)
{
    if(!this->matriz[i][k]->getJugada() && jugable(jugador,i,k) ){
        this->matriz[i][k]->cambiar(jugador);
        cambiar(jugador,i,k);
        return true;
    }else {
//        cout<<endl<<"No se pudo jugar"<<endl;
        return false;
    }
}

void Tablero::cambiar(int jugador, int i, int k)
{
    int contador=0,y,x;
    bool band=false;
    //Revisar al rededor de la ficha
    //Cambio hacia abajo
    for( y=i+1;y<8;y++){
    if(this->matriz[y][k]->getJugada() && matriz[y][k]->getJugador()!=jugador){
        contador++;
    }else {
        band=(matriz[y][k]->getJugador()==jugador);
        break;
    }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
//     cout<<endl<<"Contador hacia abajo-> "<<contador<<endl;
    if(contador!=0 && band){
        for( y=i+1; contador>=0 ; contador--,y++ ){
//            cout<<endl<<"CAMBIO HACIA ABAJO REALIZADO"<<endl;
            this->matriz[y][k]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio hacia abajo

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio hacia arriba
    for( y=i-1;y>=0;y--){
    if(this->matriz[y][k]->getJugada() && matriz[y][k]->getJugador()!=jugador){
        contador++;
    }else {
        band=(matriz[y][k]->getJugador()==jugador);
        break;
    }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
    if(contador!=0 && band){
        for( y=i-1; contador>=0 ; contador--,y-- ){
            this->matriz[y][k]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio hacia arriba

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio hacia derecha
    for( x=k+1;x<8;x++){
    if(this->matriz[i][x]->getJugada() && matriz[i][x]->getJugador()!=jugador){
        contador++;
    }else {
        band=(matriz[i][x]->getJugador()==jugador /*&& contador>3*/);
        break;
    }
    }//Verificacion y conteo de las fichas cambiar, de haber cambio

    if(contador!=0 && band){
        for( x=k+1; contador>=0 ; contador--,x++ ){
            this->matriz[i][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio hacia derecha

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio hacia derecha
    for( x=k-1;x>=0;x--){
    if(this->matriz[i][x]->getJugada() && matriz[i][x]->getJugador()!=jugador){
        contador++;
    }else {
        band=(matriz[i][x]->getJugador()==jugador);
        break;
    }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio

    if(contador!=0 && band){
        for( x=k-1; contador>=0 ; contador--,x-- ){
            this->matriz[i][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio hacia izquierda

    //Diagonarles -------------------------

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera

    //Cambio diagonal inferior derecha
    for( y=i+1,x=k+1 ; y<8 && x<8; y++,x++){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
            contador++;
        }else {
            band=(matriz[y][x]->getJugador()==jugador);
            break;
        }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
    if(contador!=0 && band){
        for( x=k+1,y=i+1; contador>=0 ; contador--, y++, x++ ){
            this->matriz[y][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio diagonal inferior derecha

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio diagonal inferior izquierda
    for( y=i+1,x=k-1 ; y<8 && x>=0; y++,x--){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
            contador++;
        }else {
            band=(matriz[y][x]->getJugador()==jugador);
            break;
        }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
    if(contador!=0 && band){
        for( y=i+1,x=k-1 ; contador>=0 ; contador--, y++, x-- ){
            this->matriz[y][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio diagonal inferior izquierda

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio diagonal superior derecha
    for( y=i-1,x=k+1 ; y>=0 && x<8; y--,x++){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
            contador++;
        }else {
            band=(matriz[y][x]->getJugador()==jugador);
            break;
        }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
    if(contador!=0 && band){
        for( y=i-1,x=k+1 ; contador>=0 ; contador--, y--, x++ ){
            this->matriz[y][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio diagonal superior derecha

    contador=0;//Reinicializacion del contador
    band=false;//Reinicializacion de la bandera
    //Cambio diagonal superior izquierda
    for( y=i-1,x=k-1 ; y>=0 && x>=0; y--,x--){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
            contador++;
        }else {
            band=(matriz[y][x]->getJugador()==jugador);
            break;
        }

    }//Verificacion y conteo de las fichas cambiar, de haber cambio
    if(contador!=0 && band){
        for( y=i-1,x=k-1 ; contador>=0 ; contador--, y--, x-- ){
            this->matriz[y][x]->cambiar(jugador);
        }
    }//Cambio de las fichas necesarias
    // Fin Cambio diagonal superior izquierda
}

bool Tablero::jugable(int jugador, int i, int k)
{
    int y,x,contador=0;
    if(this->matriz[i][k]->getJugada())
        return 0;
    //Revisar al rededor de la ficha
    // Camino hacia abajo
    for( y=i+1;y<8;y++){
    if(this->matriz[y][k]->getJugada() && matriz[y][k]->getJugador()!=jugador){
    contador++;
    }else {
//        cout<<"CONTADOR HACIA ABAJO: "<<contador<<endl;
        if(matriz[y][k]->getJugador()==jugador && contador>0)
            return true;
        break;
    }

    }//Verificar si hay una ficha hacia abajo del mismo jugador
    // Fin camino hacia abajo

        contador=0;
    //Camino hacia arriba
    for( y=i-1;y>=0;y--){
    if(this->matriz[y][k]->getJugada() && matriz[y][k]->getJugador()!=jugador){
    contador++;
    }else {
        if(matriz[y][k]->getJugador()==jugador && contador>0)
            return true;
        break;
    }
    }
    // Fin Camino hacia arriba

    //Camino hacia derecha
    contador=0;
    for( x=k+1;x<8;x++){
    if(this->matriz[i][x]->getJugada() && matriz[i][x]->getJugador()!=jugador){
    contador++;
    }else {
        if(matriz[i][x]->getJugador()==jugador && contador>0)
            return true;
        break;
    }
    }

    // Fin Camino hacia derecha
    contador=0;
    //Camino hacia derecha
    for( x=k-1;x>=0;x--){
    if(this->matriz[i][x]->getJugada() && matriz[i][x]->getJugador()!=jugador){
    contador++;
    }else {
        if(matriz[i][x]->getJugador()==jugador && contador>0)
            return true;
        break;
    }

    }
    // Fin Camino hacia izquierda

    //Diagonarles -------------------------
    contador=0;
    //Camino diagonal inferior derecha
    for( y=i+1,x=k+1 ; y<8 && x<8; y++,x++){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
        contador++;
        }else {
            if(matriz[y][x]->getJugador()==jugador && contador>0)
                return true;
            break;
        }

    }
    // Fin Camino diagonal inferior derecha
    contador=0;
    //Camino diagonal inferior izquierda
    for( y=i+1,x=k-1 ; y<8 && x>=0; y++,x--){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
        contador++;
        }else {
            if(matriz[y][x]->getJugador()==jugador && contador>0)
                return true;
            break;
        }

    }
    // Fin Camino diagonal inferior izquierda
    contador=0;
    //Camino diagonal superior derecha
    for( y=i-1,x=k+1 ; y>=0 && x<8; y--,x++){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
        contador++;
        }else {
            if(matriz[y][x]->getJugador()==jugador && contador>0)
                return true;
            break;
        }

    }
    // Fin Camino diagonal superior derecha
    contador=0;
    //Camino diagonal superior izquierda
    for( y=i-1,x=k-1 ; y>=0 && x>=0; y--,x--){
        if(this->matriz[y][x]->getJugada() && matriz[y][x]->getJugador()!=jugador){
        contador++;
        }else {
            if(matriz[y][x]->getJugador()==jugador && contador>0)
                return true;
            break;
        }

    }
    // Fin Camino diagonal superior izquierda
    return false;

}

void Tablero::inicializar()
{
    this->matriz[3][3]->cambiar(2);
    this->matriz[4][4]->cambiar(2);
    this->matriz[3][4]->cambiar(1);
    this->matriz[4][3]->cambiar(1);

}

int Tablero::puntajeActual(int jugador)
{
    int cont=0;
    for(int i=0 ; i<8 ; i++){
        for(int k=0; k<8; k++){
        if( this->matriz[i][k]->getJugador() == jugador)
            cont++;
        }
    }
    return cont;
}

Ficha *Tablero::getFicha(int i, int k)
{
    return this->matriz[i][k];
}

void Tablero::copiar(Tablero *obj)//En el atributo va a estar la copia
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            obj->matriz[i][j]->copiar(this->matriz[i][j]);
}

void Tablero::calcularPistas(int jugador)
{
    this->vaciarPistas();
    for(int i=0;i<8;i++){
        for (int k = 0; k < 8; ++k) {
            if(jugable(jugador,i,k))
                matriz[i][k]->setJugador(3);
        }
    }
}

void Tablero::vaciarPistas()
{
    for(int i=0;i<8;i++){
        for (int k = 0; k < 8; ++k) {
            if(matriz[i][k]->getJugador()==3)
                matriz[i][k]->setJugador(0);
        }
    }
}
