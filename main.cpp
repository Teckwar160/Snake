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
    char **tableroCopia = nullptr;
    Snake *serpiente = new Snake();
    bool game = false;
    bool comida = false;
    char Tecla = '0';

    /*Cambiamos el modo de pantalla para usar curses y la función kbhit*/
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);  

    t -> mensaje('B');
    t -> muestra();

    /*Evitamos que se cierre el juego*/
    while(Tecla != 'e' && Tecla != 'k'){
        if(kbhit()){
            Tecla = getch();
        }
    }    

    t -> mensaje('b');

    serpiente -> pinta(t);
    t -> generadorDeComida();

    while(!game && Tecla != 'k'){

        /*Mostramos el tablero*/

        t -> mostrarPuntos(serpiente -> getPuntos());
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
        std::this_thread::sleep_for (std::chrono::milliseconds(70/*50*/));

        if(serpiente -> getPuntos() == 1000){
            game = true;
        }

    }

    if(game && serpiente -> getPuntos() < 1000){
        t -> mensaje('G');
        t -> muestra();

        /*Evitamos que se cierre el juego*/
        while(getch() != 'k'){
            /*No necesitamos nada aquí*/
        }   
    }

    if(game && serpiente -> getPuntos() == 1000){
        t -> mensaje('W');
        t -> muestra();

        /*Evitamos que se cierre el juego*/
        while(getch() != 'k'){
            /*No necesitamos nada aquí*/
        }   
    }
    


    /*Fin del cambio de modo*/
    endwin();

    /*Liberamos la memoria*/
    if(tableroCopia != nullptr){
       t -> borrarCopia(tableroCopia); 
    }
    
    delete t;
    delete serpiente;

}