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
    for(size_t i = 3; i>0; i--){
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


    if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' || Tecla == 'd'){
        
        PedazoSnake *cabeza;

        this -> Pedazos -> CursorFirst();

        this -> Pedazos -> Peek(&cabeza);

        if(cabeza -> getDireccion() != Tecla){
            cabeza -> setDireccion(Tecla);

            this -> PuntosCriticos -> InsertBack(new Punto(cabeza -> getX(),cabeza -> getY()));
        }

    }

}

void Snake::mueve(Tablero *t){

    PedazoSnake *P;
    PedazoSnake *cabeza;
    Punto *puntoCritico;
    /*Limites del tablero*/
    int limiteX;
    int limiteY;

    /*Para no dejar rastro*/
    this -> borrar(t);

    /*Obtenemos los limites del tablero*/
    limiteX = t -> getColumnas();
    limiteY = t -> getFilas();

    this -> Pedazos -> CursorFirst();
    this -> Pedazos -> Peek(&cabeza);

    this -> PuntosCriticos -> CursorFirst();

    for(size_t i = 0; i<this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&P);

        /*Verificamos si el pedazo esta en un punto critico*/

        for(size_t i = 0; i< this -> PuntosCriticos -> Len(); i++){

            this -> PuntosCriticos -> Peek(&puntoCritico);

            if(P -> getX() == puntoCritico -> getX() && P -> getY() == puntoCritico -> getY()){
                P -> setDireccion(cabeza -> getDireccion());
                puntoCritico -> incrementaContador();
            }

            if(puntoCritico -> getContador() == this -> Pedazos -> Len()){
                this -> PuntosCriticos -> RemoveFront(&puntoCritico);
            }

            this -> PuntosCriticos -> CursorNext();
        }


        /*Movemos segun la dirección que tenga cada pedazo*/
        switch(P -> getDireccion()){
            case 'w':
                if(P -> getY()-1 > 0){
                    P -> setY(P -> getY()-1);
                }else{
                  P -> setY(limiteY-1);
                }
                
                break;
            case 'a':
                if(P -> getX()-1 > 0){
                    P -> setX(P -> getX()-1);
                }else{
                    P -> setX(limiteX-1);
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

