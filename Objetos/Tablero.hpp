#include <iostream>
#include <curses.h>

class Tablero{
    private:
        size_t filas;
        size_t columnas;
        char **tablero;
        char fondo = '.';
    
    public:
        Tablero(size_t filas, size_t columnas);
        ~Tablero();
        void muestra();
        char **getTablero();
        size_t getFilas();
        size_t getColumnas();
        char getFondo();
        char **copiaTablero();
        void borrarCopia(char **copia);
};