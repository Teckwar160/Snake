#include <iostream>
#include <curses.h>
#include <fstream>
#include <ctime>

class Tablero{
    private:
        size_t filas;
        size_t columnas;
        char **tablero;
        char fondo = '.';
        char comida = '@';
    
    public:
        Tablero();
        ~Tablero();
        void muestra();
        char **getTablero();
        size_t getFilas();
        size_t getColumnas();
        char getFondo();
        char **copiaTablero();
        void borrarCopia(char **copia);
        void generadorDeComida();
        void mostrarPuntos(size_t puntos);
        void mensaje(char comando);
};