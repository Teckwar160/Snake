#ifndef PEDAZO_SNAKE_HPP
#define PEDAZO_SNAKE_HPP

#include <iostream>

class PedazoSnake{
    private:
        int x;
        int y;
        char pieza = '*';
        char cabeza = '$';
        char direccion;
    public:
        PedazoSnake(int x, int y, char direccion);

        ~PedazoSnake();

        void pinta(char **tablero,bool cabeza);
        
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        void setDireccion(char direccion);
        char getDireccion();
        char getPieza();
};

#endif