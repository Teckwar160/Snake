#include "Punto.hpp"

Punto::Punto(size_t x, size_t y){
    this -> x = x;
    this -> y = y;
    this -> contador = 0;
}

Punto::~Punto(){

}

size_t Punto::getX(){
    return this -> x;
}

size_t Punto::getY(){
    return this -> y;
}

void Punto::setContador(size_t contador){
    this -> contador = contador;
}
size_t Punto::getContador(){
    return this -> contador;
}