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
    for(size_t i = 1; i>0; i--){
        this -> crearPedazo(i+5,5);
    }
}

Snake::~Snake(){
   this -> Pedazos -> Traverse(this -> liberarPedazo);
   this -> PuntosCriticos -> Traverse(this -> liberarPunto);
   delete this -> Pedazos;
   delete this -> PuntosCriticos;
}

bool Snake::crearPedazo(int x, int y){
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
void Snake::actualizacion(char Tecla){

    PedazoSnake *cabeza;

    /*Actualizamos la dirección de la cabeza de la serpiente*/
    if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' || Tecla == 'd'){
        this -> Pedazos -> CursorFirst();
        this -> Pedazos -> Peek(&cabeza);

        cabeza -> setDireccion(Tecla);

    }
}

void Snake::movimiento(char Tecla){
    actualizacion(Tecla);

}



void Snake::mueve(Tablero *t){

    this -> Pedazos -> CursorFirst();
    PedazoSnake *tmp;

    for(size_t i = 0; i< this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&tmp);

        switch(tmp -> getDireccion()){
            case 'w':
                /*Se verifica si todavia esta en el tablero*/
                if(tmp -> getY()-1 < 0){
                    tmp -> setY(t -> getFilas()-1);
                }else{
                    tmp -> setY(tmp -> getY()-1);
                }
                break;
            case 'a':
                /*Se verifica si todavia sigue en el tablero*/
                if(tmp -> getX()-1 < 0){
                    tmp -> setX(t -> getColumnas()-1);
                }else{
                    tmp -> setX(tmp -> getX()-1);
                }
                break;
            case 's':
                /*Se verifica si todavia esta en el tablero*/
                if(tmp -> getY()+1 > t -> getFilas()-1){
                    tmp -> setY(0);
                }else{
                    tmp -> setY(tmp -> getY()+1);
                }
                break;
            case 'd':

                /*Se verifica si todavia sigue en el tablero*/
                if(tmp -> getX()+1 > t -> getColumnas()-1){
                    tmp -> setX(0);
                }else{
                    tmp -> setX(tmp -> getX()+1);
                }
                
                break;
        }

        this -> Pedazos -> CursorNext();
    }
}

