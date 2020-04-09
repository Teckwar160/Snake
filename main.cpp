#include <iostream>
#include "Objetos/Snake.hpp"
#include <stdlib.h>

/**!<Biblioteca para moverse en pantalla*/
#include <curses.h>

/**!<Para manejo de hilos*/
#include <thread>        

/**!<Para uso del tiempo*/ 
#include <chrono>

/**
 * @brief Función que checa si se pulso una tecla
 * @return 1 Si si se pulso una tecla 0 en caso contrario
 */
int kbhit()
{
    int ch = getch();
 
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int main(){
#if 1
    Tablero *t = new Tablero(30,100);
    Snake *serpiente = new Snake();
    bool game = true;
    char Tecla = '0';

    serpiente -> pinta(t);

    /*Cambiamos el modo de pantalla para usar curses y la función kbhit*/
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);   

    t -> muestra(); 

    while(game && Tecla != 'k'){
        t -> muestra();

        if(kbhit()){
            Tecla = getch();
            serpiente -> movimiento(Tecla);
        }

        /*Bloque de movimiento de serpiente*/
        serpiente -> borrar(t);
        serpiente -> mueve(t);
        serpiente -> pinta(t);
        /*----------------------------------*/

        /*Borramos el tablero*/
        erase();

        /*Dormimos el hilo para que no haga cosas extrañas*/
        std::this_thread::sleep_for (std::chrono::milliseconds(50/*50*/));
    }

    /*Fin del cambio de modo*/
    endwin();

    delete t;
    delete serpiente;
#endif
}