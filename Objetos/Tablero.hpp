#include <iostream>

class Tablero{
    private:
        size_t filas;
        size_t columnas;
        char **tablero;
        char fondo = '0';
    
    public:
        Tablero(size_t filas, size_t columnas);
        ~Tablero();
        void muestra();
        char **getTablero();
};