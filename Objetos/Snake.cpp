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
        this -> crearPedazo(i+5,5,'d');
    }
}

Snake::~Snake(){
   this -> Pedazos -> Traverse(this -> liberarPedazo);
   this -> PuntosCriticos -> Traverse(this -> liberarPunto);
   delete this -> Pedazos;
   delete this -> PuntosCriticos;
}

bool Snake::crearPedazo(int x, int y, char direccion){
    return this -> Pedazos -> InsertBack(new PedazoSnake(x,y,direccion));

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
    char direccion;

    /*Actualizamos la dirección de la cabeza de la serpiente*/
    if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' || Tecla == 'd'){
        this -> Pedazos -> CursorFirst();
        this -> Pedazos -> Peek(&cabeza);
        direccion = cabeza -> getDireccion();

        if(direccion == 'w' && Tecla != 's'){
            cabeza -> setDireccion(Tecla);
        }

        if(direccion == 's' && Tecla != 'w'){
            cabeza -> setDireccion(Tecla);
        }

        if(direccion == 'a' && Tecla != 'd'){
            cabeza -> setDireccion(Tecla);
        }

        if(direccion == 'd' && Tecla != 'a'){
            cabeza -> setDireccion(Tecla);
        }
    }
}

void Snake::movimiento(char Tecla){

    /*Actualizamos la posicion de la cabeza*/
    this -> actualizacion(Tecla);

    /*Obtenemos a la cabeza*/
    this -> Pedazos -> CursorFirst();
    PedazoSnake *cabeza;
    this -> Pedazos -> Peek(&cabeza);
    /*---------------------*/

    /*Creamos al punto critico de movimiento*/
    this -> PuntosCriticos ->InsertBack(new Punto(cabeza -> getX(),cabeza -> getY(),cabeza -> getDireccion()));

}



bool Snake::mueve(Tablero *t,char **copia,bool *comida){

    PedazoSnake *tmp;
    PedazoSnake *cabeza;
    Punto *puntoCritico;

    /*Obtenemos a la cabeza*/
    this -> Pedazos -> CursorFirst();
    this -> Pedazos -> Peek(&cabeza);
    this -> Pedazos -> CursorNext();

    /*Vemos si algun pedazo de la serpiente esta en un punto critico*/


    /*Recorremos a los pedazos del cuerpo*/
    for(size_t i = 1; i< this -> Pedazos -> Len(); i++){

        this -> Pedazos -> Peek(&tmp);

        this -> PuntosCriticos -> CursorFirst();

        /*Recorremos los puntos criticos*/
        for(size_t j = 0; j< this -> PuntosCriticos -> Len(); j++){
            this -> PuntosCriticos -> Peek(&puntoCritico);

            /*Vemos si sus cordenadas son iguales*/
            if(tmp -> getY() == puntoCritico -> getY()){
                if(tmp -> getX() == puntoCritico -> getX()){

                    /*Actualizamos su dirección con la del punto*/
                    tmp -> setDireccion(puntoCritico -> getDireccion());

                    /*Aumentamos el contador del punto*/
                    puntoCritico -> setContador(puntoCritico -> getContador()+1);
                }
            }

            /*Vemos si ya cumplio su cometido el punto*/
            if(puntoCritico -> getContador() == this -> Pedazos -> Len()-1){
                this -> PuntosCriticos -> RemoveFront(&puntoCritico);
            }

            this -> PuntosCriticos -> CursorNext();
        }
           
        this -> Pedazos -> CursorNext();           
    }

    /*Movemos a la serpiente segun su dirección*/
    this -> Pedazos -> CursorFirst();
 

    for(size_t i = 0; i< this -> Pedazos -> Len(); i++){
        this -> Pedazos -> Peek(&tmp);

        switch(tmp -> getDireccion()){
            case 'w':
                /*Se verifica si todavia esta en el tablero*/
                if(tmp -> getY()-1 < 0){
                    tmp -> setY(t -> getFilas()-4);
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
                if(tmp -> getY()+1 > t -> getFilas()-4){
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

        if(i == 0){
            if(this -> choco(copia,comida)){
                return true;
            }
        }

        this -> Pedazos -> CursorNext();
    }
    return false;
}

bool Snake::choco(char **t,bool*comida){

    this -> Pedazos -> CursorFirst();
    PedazoSnake *cabeza;
    this -> Pedazos -> Peek(&cabeza);

    if(t[cabeza -> getY()][cabeza -> getX()] == '@'){
        *comida = true;
    }

    if(t[cabeza -> getY()][cabeza -> getX()] == cabeza -> getPieza()){
        return true;
    }

    return false;

}

void Snake::crecerSnake(){

    PedazoSnake *cola;
    int x,y;

    /*Obtenemos el ultimo elemento de la snake*/
    this -> Pedazos -> CursorLast();
    this -> Pedazos -> Peek(&cola);

    /*Vemos la dirección que lleva*/

    switch(cola -> getDireccion()){
        case 'w':
            x = cola -> getX();
            y = cola -> getY()+1;
            break;
        case 'a':
            x = cola -> getX()+1;
            y = cola -> getY();
            break;
        case 's':
            x = cola -> getX();
            y = cola -> getY() -1;
            break;
        case 'd':
            x = cola -> getX() -1;
            y = cola -> getY();
            break;
    }

    this -> crearPedazo(x,y,cola -> getDireccion());
}

