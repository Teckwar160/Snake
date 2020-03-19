#ifndef PEDAZO_SNAKE_HPP
#define PEDAZO_SNAKE_HPP

#include <iostream>

class PedazoSnake{
    private:
        size_t x;
        size_t y;
        char pieza = '*';
    public:
        PedazoSnake(size_t x, size_t y);

        ~PedazoSnake();

        void pinta(char **tablero);
        
        void setX(size_t x);
        void setY(size_t y);
        size_t getX();
        size_t getY();
};

#endif