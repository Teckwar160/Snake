#include "Snake.hpp"

void Snake::liberarPedazo(PedazoSnake *P){
    delete P;
}

Snake::Snake(){
    this -> vive = true;
    this -> puntos = 0;
    this -> Pedazos = new DLL<PedazoSnake *>();

    /**!<Crea los pedazos iniciales de la Snake*/
    for(size_t i = 3; i>0; i--){
        this -> crearPedazo(i+5,5);

        if(i == 3){
            this -> cabezaX = i+5;
            this -> cabezaY = 5;
        }
    }
}

Snake::~Snake(){
   this -> Pedazos -> Traverse(this -> liberarPedazo);
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

void Snake::mueve(Tablero *t){

    PedazoSnake *P;
    int limiteX;
    int limiteY;

    this -> borrar(t);

    limiteX = t -> getColumnas();
    limiteY = t -> getFilas();

    this -> Pedazos -> CursorFirst();

    for(size_t i = 0; i<this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&P);

        switch(P -> getDireccion()){
            case 'w':
                if(P -> getY()-1 > 0){
                    P -> setY(P -> getY()-1);
                }else{
                    P -> setY(limiteY);
                }
                
                break;
            case 'a':
                if(P -> getX()-1 > 0){
                    P -> setX(P -> getX()-1);
                }else{
                    P -> setX(limiteX);
                }
                
                break;
            case 's':
                if(P -> getY()+1 < limiteY){
                    P -> setY(P -> getY()+1);
                }else{
                    P -> setY(0);
                }
                
                break;
            case 'd':
                if(P -> getX()+1 < limiteX){
                    P -> setX(P -> getX()+1);
                }else{
                    P -> setX(0);
                }
                
                break;
        }


        this -> Pedazos -> CursorNext();
    }

}

