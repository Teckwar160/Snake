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

    Tablero *t = new Tablero();
    char **tableroCopia;
    Snake *serpiente = new Snake();
    bool game = false;
    bool comida = false;
    char Tecla = '0';

    serpiente -> pinta(t);

    /*Cambiamos el modo de pantalla para usar curses y la función kbhit*/
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);   

    t -> muestra(); 
    t -> generadorDeComida();

    while(!game && Tecla != 'k'){

        /*Mostramos el tablero*/
        t -> muestra();

        /*Prueba de comida*/
        if(comida){
            t -> generadorDeComida();
            serpiente -> crecerSnake();
            comida = false;
        }
        

        /*Cachamos la tecla precionada*/
        if(kbhit()){
            Tecla = getch();
            serpiente -> movimiento(Tecla);
        }

        /*Bloque de movimiento de serpiente*/
        tableroCopia = t -> copiaTablero();
        serpiente -> borrar(t);
        game = serpiente -> mueve(t,tableroCopia,&comida);
        serpiente -> pinta(t);
        /*----------------------------------*/

        /*Borramos el tablero*/
        erase();

        /*Dormimos el hilo para que no haga cosas extrañas*/
        std::this_thread::sleep_for (std::chrono::milliseconds(50/*50*/));

    }

    /*Fin del cambio de modo*/
    endwin();

    /*Liberamos la memoria*/
    t -> borrarCopia(tableroCopia);
    delete t;
    delete serpiente;

}