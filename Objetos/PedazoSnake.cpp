#include "PedazoSnake.hpp"

PedazoSnake::PedazoSnake(int x, int y, char direccion){
    this -> x = x;
    this -> y = y;
    this -> direccion = direccion;
}

PedazoSnake::~PedazoSnake(){
    /*Destructro vacío*/
}

void PedazoSnake::setX(int x){
    this -> x = x;
}

void PedazoSnake::setY(int y){
    this -> y = y;
}

int PedazoSnake::getX(){
    return this -> x;
}

int PedazoSnake::getY(){
    return this -> y;
}

void PedazoSnake::pinta(char **tablero,bool cabeza){
    if(!cabeza){
        tablero[this -> y][this -> x] = this -> pieza;
    }else{
        tablero[this -> y][this -> x] = this -> cabeza;
    }
    
}

void PedazoSnake::setDireccion(char direccion){
    this -> direccion = direccion;
}

char PedazoSnake::getDireccion(){
    return this -> direccion;
}

char PedazoSnake::getPieza(){
    return this -> pieza;
}