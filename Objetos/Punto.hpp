#include <iostream>

class Punto{
    private:
        size_t x;
        size_t y;
        size_t contador;
    public:
        Punto(size_t x, size_t y);
        ~Punto();
        size_t getX();
        size_t getY();
        void incrementaContador();
        size_t getContador();
};