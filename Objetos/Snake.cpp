#include "Snake.hpp"

void Snake::liberarPedazo(PedazoSnake *P){
    delete P;
}

Snake::Snake(){
    this -> vive = true;
    this -> puntos = 0;
    this -> Pedazos = new DLL<PedazoSnake *>();

    /**!<Crea los pedazos iniciales de la Snake*/
    for(size_t i = 0; i<3; i++){
        this -> crearPedazo(i+5,5);
    }
}

Snake::~Snake(){
   this -> Pedazos -> Traverse(this -> liberarPedazo);
}

bool Snake::crearPedazo(size_t x, size_t y){
    return this -> Pedazos -> InsertBack(new PedazoSnake(x,y));

}

void Snake::pinta(char **tablero){

    PedazoSnake *P;

    this -> Pedazos -> CursorFirst();

    for(size_t i = 0; i< this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&P);

        P -> pinta(tablero);
        this -> Pedazos -> CursorNext();
    }
}

