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

void Tablero::generadorDeComida(){

    /*Limites en lso que puede aparecer la comida*/
    int desdeX = 0, hastaX = 99;
    int desdeY = 0, hastaY = 26;
    int x,y;

    srand(time(NULL));
    x = rand()%(hastaX-desdeX+1)+ desdeX;
    y = rand()%(hastaY-desdeY+1)+ desdeY;

    /*Pintamos la comida*/
    this -> tablero[y][x] = this -> comida;



}

void Tablero::mostrarPuntos(size_t puntos){
    
    int puntosX = 12;
    int puntosY = 28;

    /*Separamos el numero*/
    int millares = puntos/1000;
    int centenas = (puntos - (millares *1000))/100;
    int decenas = (puntos - (millares*1000 + centenas*100))/10;
    int unidades = puntos -(millares*1000 + centenas*100 +decenas*10);

    /*Actualizamos los puntos en el pantalla*/
    this -> tablero[puntosY][puntosX] = '0' + unidades;
    this -> tablero[puntosY][puntosX -1] = '0' + decenas;
    this -> tablero[puntosY][puntosX -2] = '0' + centenas;
    this -> tablero[puntosY][puntosX -3] = '0' + millares;

}

void Tablero::mensaje(char comando){

    std::ifstream mensaje;
    std::string dirreccionMensaje;
    int x,y;

    switch(comando){
        case 'B':
            dirreccionMensaje = "Sprites/Bienvenida.txt";
            y=4;
            x=0;
            break;
        case 'b':
            dirreccionMensaje = "Sprites/Tablero.txt";
            y = 0;
            x = 0;
            break;
        case 'G':
            dirreccionMensaje = "Sprites/GameOver.txt";
            y=28;
            x=63;
            break;
        case 'W':
            dirreccionMensaje = "Sprites/Win.txt";
            y=28;
            x=63;       
            break;
    }

    mensaje.open(dirreccionMensaje,std::ios::in);

    if(!mensaje.fail()){
        for(size_t i = 0; i<this -> filas; i++){
            for(size_t j = 0; j<this -> columnas; j++){
                mensaje >> this -> tablero[y+i][x+j];
            }
        }
    }else{
        std::cout << "Fallo #2" << std::endl;
    }

    mensaje.close();
}
#endif