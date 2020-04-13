/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "Tablero.hpp"
#include <stdio.h>

Tablero::Tablero(){

    /*Variables para leer el tablero*/
    std::string direccionDimension = "Sprites/MedidasTablero.txt";
    std::string direecionSprite = "Sprites/Tablero.txt";
    std::ifstream sprite;
    std::ifstream dimension;

    /*Cargamos las dimensiones del tablero*/
    dimension.open(direccionDimension,std::ios::in);

    if(!dimension.fail()){
        dimension >> this -> filas;
        dimension >> this -> columnas;
    }else{
        std::cout << "Fallo #0" << std::endl;
    }

    dimension.close();
    
    /*Cargamos el tablero*/
    sprite.open(direecionSprite,std::ios::in);

    if(!sprite.fail()){

        /*Creamos a la matriz que llevara al tablero*/
        this -> tablero = new char*[this -> filas];

        for(size_t i = 0; i< this -> filas; i++){
            this -> tablero[i] = new char[this -> columnas];
        }

        /*Cargamos al tablero*/
        for(size_t i = 0; i<this -> filas; i++){
            for(size_t j = 0; j<this -> columnas; j++){
                sprite >> this -> tablero[i][j];
            }
        }        
    }else{
        std::cout << "Fallo #1" << std::endl;
    }

    sprite.close();

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
            printw("%c",this -> tablero[i][j]);
        }
        printw("\n");
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

char **Tablero::copiaTablero(){
    char **viejo = new  char*[this -> filas];

    for(size_t i = 0; i< this -> filas; i++){
        viejo[i] = new char[this -> columnas];
    }

    for(size_t i = 0; i<this -> filas; i++){
        for(size_t j = 0; j<this -> columnas; j++){
            viejo[i][j] = this -> tablero[i][j];
        }
    }

    return viejo;

}

void Tablero::borrarCopia(char **copia){

    for(size_t i = 0; i<this -> filas; i++){
        delete[] copia[i];
    }

    delete[] copia;   
}
#endif