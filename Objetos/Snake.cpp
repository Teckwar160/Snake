#include "Snake.hpp"

void Snake::liberarPedazo(PedazoSnake *P){
    delete P;
}

void Snake::liberarPunto(Punto *punto){
    delete punto;
}

Snake::Snake(){
    this -> vive = true;
    this -> puntos = 0;
    this -> Pedazos = new DLL<PedazoSnake*>();
    this -> PuntosCriticos = new DLL<Punto*>();

    /**!<Crea los pedazos iniciales de la Snake*/
    for(size_t i = 4; i>0; i--){
        this -> crearPedazo(i+5,5);
    }
}

Snake::~Snake(){
   this -> Pedazos -> Traverse(this -> liberarPedazo);
   this -> PuntosCriticos -> Traverse(this -> liberarPunto);
   delete this -> Pedazos;
   delete this -> PuntosCriticos;
}

bool Snake::crearPedazo(size_t x, size_t y){
    return this -> Pedazos -> InsertBack(new PedazoSnake(x,y));

}

void Snake::pinta(Tablero *t){

    PedazoSnake *P;
    char **tablero = t -> getTablero();
    this -> Pedazos -> CursorFirst();

    for(size_t i = 0; i< this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&P);

        if(i != 0){
            P -> pinta(tablero,false);
        }else{
            P -> pinta(tablero,true);
        }
        
        this -> Pedazos -> CursorNext();
    }
}

void Snake::borrar(Tablero *t){
    PedazoSnake *P;
    char **tablero = t -> getTablero();

    this -> Pedazos -> CursorFirst();

    for(size_t i = 0; i< this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&P);

        tablero[P -> getY()][P -> getX()] = t -> getFondo();
        
        this -> Pedazos -> CursorNext();
    }   
}

void Snake::movimiento(char Tecla){

}

void Snake::actualizacion(){

}

void Snake::mueve(Tablero *t){

}

