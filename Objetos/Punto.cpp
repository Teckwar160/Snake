#include "Punto.hpp"

Punto::Punto(int x, int y, char direccion){
    this -> x = x;
    this -> y = y;
    this -> contador = 0;
    this -> direccion = direccion;
}

Punto::~Punto(){

}

int Punto::getX(){
    return this -> x;
}

int Punto::getY(){
    return this -> y;
}

void Punto::setContador(size_t contador){
    this -> contador = contador;
}
size_t Punto::getContador(){
    return this -> contador;
}

char Punto::getDireccion(){
	return this -> direccion;
}