#include "Punto.hpp"

Punto::Punto(size_t x, size_t y){
    this -> x = x;
    this -> y = y;
}

Punto::~Punto(){

}

size_t Punto::getX(){
    return this -> x;
}

size_t Punto::getY(){
    return this -> y;
}

void Punto::incrementaContador(){
    this -> contador++;
}
size_t Punto::getContador(){
    return this -> contador;
}