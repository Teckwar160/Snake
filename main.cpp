#include <iostream>
#include "Objetos/Snake.hpp"
#include <conio.h>


int main(){
    Tablero *t = new Tablero(10,30);
    Snake *serpiente = new Snake();
    bool game = true;
    int Tecla = 0;

    serpiente -> pinta(t -> getTablero());

    while(game && Tecla != 'k'){

        if(kbhit()){
            Tecla = getch();
            t -> muestra();
            serpiente -> mueve(t);
            serpiente -> pinta(t -> getTablero());

        }
    }

    delete t;
    delete serpiente;
}