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
        void setContador(size_t contador);
        size_t getContador();
};