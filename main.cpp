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
    int i = 10;

    serpiente -> pinta(t);

    while(game && Tecla != 'k'){
        t -> muestra();
        serpiente -> mueve(t);
        serpiente -> actualizacion();
        if(kbhit()){
            Tecla = getch();
            if(i < 10){
                serpiente -> movimiento(Tecla);
            }else{
                i = 10;
            }
            
        }



        serpiente -> pinta(t);
        system("cls");

        Sleep(30);
        i--;
    }

    delete t;
    delete serpiente;
}