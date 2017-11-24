#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo {

        T dato;
        Nodo<T> *siguiente, *anterior;

        public:

        Nodo() { siguiente  = NULL; }
        Nodo(T dato) { this -> dato = dato; siguiente  = NULL; anterior = NULL; }

        void setDato(T dato) { this -> dato = dato; }
        void setSiguiente(Nodo<T> *p) { siguiente = p; }
        void setAnterior(Nodo<T> *p) { anterior = p; }
        T getDato() { return dato; }
        Nodo<T>* getSiguiente() { return siguiente; }
        Nodo<T>* getAnterior() { return anterior; }
};

#endif
