#include <iostream>
#include "Objetos/Snake.hpp"
#include "Objetos/Tablero.hpp"


int main(){
    Tablero *t = new Tablero(10,10);
    Snake *serpiente = new Snake();

    t -> muestra();

    std::cout << std::endl << std::endl;

    serpiente -> pinta(t -> getTablero());

    t -> muestra();
    delete t;
}