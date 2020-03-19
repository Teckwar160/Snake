#include "PedazoSnake.hpp"

PedazoSnake::PedazoSnake(size_t x, size_t y){
    this -> x = x;
    this -> y = y;
}

PedazoSnake::~PedazoSnake(){
    /*Destructro vacío*/
}

void PedazoSnake::setX(size_t x){
    this -> x = x;
}

void PedazoSnake::setY(size_t y){
    this -> y = y;
}

size_t PedazoSnake::getX(){
    return this -> x;
}

size_t PedazoSnake::getY(){
    return this -> y;
}

void PedazoSnake::pinta(char **tablero){
    tablero[this -> y][this -> x] = this -> pieza;
}