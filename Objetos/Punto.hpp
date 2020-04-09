#include <iostream>

class Punto{
    private:
        int x;
        int y;
        size_t contador;
    public:
        Punto(int x, int y);
        ~Punto();
        int getX();
        int getY();
        void setContador(size_t contador);
        size_t getContador();
};