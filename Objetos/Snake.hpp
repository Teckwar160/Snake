/**!<Guardas de inclusión*/
#ifndef SNAKE_HPP
#define SNAKE_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <conio.h>
#include "PedazoSnake.hpp"
#include "DLL.hpp"

/**
 * @class Snake
 * @brief Representa al jugador del juego
 */
class Snake{
    private:
        static void liberarPedazo(PedazoSnake *P);

    private:
        bool vive;
        size_t puntos;
        DLL<PedazoSnake*> *Pedazos;
    public:
        /**
         *@brief Método constructor de Snake
         */
        Snake();

        /**
         *@brief Método destructor de Snake
         */
        ~Snake();

        bool crearPedazo(size_t x, size_t y);
        void pinta(char **tablero);

};

#endif
