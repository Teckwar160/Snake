/**!<Guardas de inclusión*/
#ifndef SNAKE_HPP
#define SNAKE_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include "PedazoSnake.hpp"
#include "DLL.hpp"
#include "Tablero.hpp"
#include "Punto.hpp"

/**
 * @class Snake
 * @brief Representa al jugador del juego
 */
class Snake{
    private:
        static void liberarPedazo(PedazoSnake *P);
        static void liberarPunto(Punto *punto);
    private:
        bool vive;
        size_t puntos;
        DLL<PedazoSnake*> *Pedazos;
        DLL<Punto*> *PuntosCriticos;

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
        void pinta(Tablero *t);
        void borrar(Tablero *t);
        void movimiento(char Tecla);
        void mueve(Tablero *t);

};

#endif
