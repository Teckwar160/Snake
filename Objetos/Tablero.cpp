/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "Tablero.hpp"

Tablero::Tablero(size_t filas, size_t columnas){
    this -> filas = filas;
    this -> columnas = columnas;
    
    this -> tablero = new char*[this -> filas];

    for(size_t i = 0; i< this -> filas; i++){
        this -> tablero[i] = new char[this -> columnas];
    }

    for(size_t i = 0; i<this -> filas; i++){
        for(size_t j = 0; j<this -> columnas; j++){
            this -> tablero[i][j] = this -> fondo;
        }
    }
}

Tablero::~Tablero(){
    for(size_t i = 0; i<this -> filas; i++){
        delete[] this -> tablero[i];
    }

    delete[] this -> tablero;
}

void Tablero::muestra(){
    for(size_t i =0; i <this -> filas; i++){
        for(size_t j = 0; j<this -> columnas; j++){
            std::cout << this -> tablero[i][j];
        }
        std::cout << std::endl;
    }
}

char **Tablero::getTablero(){
    return this -> tablero;
}

size_t Tablero::getFilas(){
    return this -> filas;
}
size_t Tablero::getColumnas(){
    return this -> columnas;
}

char Tablero::getFondo(){
    return this -> fondo;
}
#endif