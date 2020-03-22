#include <iostream>
#include "Objetos/Snake.hpp"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    Tablero *t = new Tablero(10,50);
    Snake *serpiente = new Snake();
    bool game = true;
    char Tecla = '0';

    serpiente -> pinta(t);

    while(game && Tecla != 'k'){
        t -> muestra();


        if(kbhit()){
            Tecla = getch();
            serpiente -> movimiento(Tecla);
            serpiente -> actualizacion();
        }
        serpiente -> mueve(t);
        serpiente -> pinta(t);
        system("cls");

        Sleep(30);
    }

    delete t;
    delete serpiente;
}