/**!<Guardas de inclusión*/
#ifndef DLL_HPP
#define DLL_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/**
 *@class Node
 *@brief Representa una unidad de la DLL de un tipo dinámico
 */

template <class Item>
class Node{
	public:

		/**!<Dato a guardar en el nodo*/
		Item data;

		/**!<Apuntador al nodo anterior*/
		Node *next;

		/**!<Apuntador al nodo siguiente*/
		Node *prev;

		/**
		 *@brief Método constructor de los Nodos
		 *
		 *@param _data Información a guardar en el nodo
		 *
		 */
		Node(Item _data);
};

/**
 *@class DLL
 *@brief Representa una lista doblemente enlazada
 */

template <class Item>
class DLL{
	private:
		/**!<Apuntador al primer nodo en la lista*/
		Node<Item>* first;

		/**!<Apuntador al ultimo nodo en la lista*/
		Node<Item>* last;

		/**!<Apuntador libre en la lista*/
		Node<Item>* cursor;

		/**!<Numero de elementos en la lista*/
		size_t len;

		/**
		 *@brief Método encargado de resetar los apuntadores de la DLL y a len
		 */
		void reset();
	public:
		/**
		 *@brief Método constructor de la DLL
		 */
		DLL();

		/**
		 *@brief Método destructor de la DLL
		 */
		~DLL();

		/**
		 *@brief Método que inserta un Item al final de la DLL
		 *
		 *@param _data Información a insertar en la DLL
		 *
		 *@return true si se logró insertar el nodo en la DLL, en caso contrario retorna false
		 *
		 */
		bool InsertBack(Item _data);

		/**
		 *@brief Método que inserta un Item al principio de la DLL
		 *
		 *@param _data Información a insertar en la DLL
		 *
		 *@return true si se logró insertar el nodo en la DLL, en caso contrario retorna false
		 */
		bool InsertFront(Item _data);

		/**
		 *@brief Método que inserta un nodo despues del cursor
		 *
		 *@param _data Información a insertar en la DLL
		 *
		 *@return true si se logró insertar el nodo en la DLL, en caso contrario retorna false
		 */
		bool InsertAfter(Item _data);

		/**
		 *@brief Método que inserta un nodo antes del cursor 
		 *
		 *@param _data Información a insertar en la DLL
		 *
		 *@return true si se logró insertar el nodo en la DLL, en caso contrario retorna false
		 */
		bool InsertBefore(Item _data);

		/**
		 *@brief Método que elimina el nodo al que este apuntando en cursor
		 *
		 *@param _data_back Información que contenia el nodo elimiando
		 *
		 *@return true si se logró eliminar el nodo de la DLL, en caso contrario retorna false
		 */
		bool Remove(Item* _data_back);

		/**
		 *@brief Método que elimina el primer nodo en la DLL
		 *
		 *@brief _data_back Información que contenia el nodo eliminado
		 *
		 *@return true si se logró eliminar el nodo de la DLL, en caso contrario retorna false
		 */
		bool RemoveFront(Item* _data_back);

		/**
		 *@brief Método que elimina el ultimo nodo en la DLL
		 *
		 *@param _data_back Información que contenida el nodo eliminado
		 *
		 *@return true si se logró eliminar el nodo de la DLL, en caso contrario retorna false
		 */
		bool RemoveBack(Item* _data_back);

		/**
		 *@brief Método que elimina el nodo siguiente al cursor
		 *
		 *@param _data_back Información que contenia el nodo eliminado
		 *
		 *@return true si se logró eliminar el nodo de la DLL, en caso contrario retorna false
		 */
		bool RemoveAfter(Item* _data_back);

		/**
		 *@brief Método que elimina el nodo anterior al cursor
		 *
		 *@param _data_back Información que contenia el nodo elimiando
		 *
		 *@return true si se logró eliminar el nodo de la DLL, en caso contrario retorna false
		 */
		bool RemoveBefore(Item* _data_back);

		/**
		 *@brief Método que retorna el número de nodos en la DLL
		 *
		 *@return Número de nodos en la DLL
		 */
		size_t Len();

		/**
		 *@brief Método que ve si esta vacía la DLL
		 *
		 *@return true si esta vacía la DLL, en caso contrario retorna false
		 */
		bool IsEmpty();

		/**
		 *@brief Método que vacía la DLL
		 */
		void MakeEmpty();

		/**
		 *@brief Método que nos da la información contenida en el nodo al que apunta el cursor
		 *
		 *@param _data_back Información que contiene el nodo
		 *
		 *@return true si se esta apuntando a un nodo, si se apunta a null o esta vacía la DLL retorna false
		 */
		bool Peek(Item* _data_back);

		/**
		 *@brief Mueve el cursor al primer nodo en la DLL
		 */
		void CursorFirst();

		/**
		 *@brief Mueve el cursor al ultimo nodo en la DLL
		 */
		void CursorLast();

		/**
		 *@brief Mueve el cursor al nodo siguiente
		 */
		void CursorNext();

		/**
		 *@brief Mueve el cursor al nodo anterior
		 */
		void CursorPrev();

		/**
		 *@brief Método que busca en la DLL si existe una información específica en un nodo
		 *
		 *@param _key Información a buscar en los nodos
		 *
		 *@param cmp Función que compara dos Items
		 *
		 *@return true si se encontro la información en la DLL, en caso contrario retorna false
		 */
		bool FindIf(Item _key,bool(*cmp)(Item,Item));

		/**
		 *@brief Método que busca en la DLL si existe una información específica en un nodo y mueve el cursor a este
		 *
		 *@param _key Información a buscar en los nodos
		 *
		 *@param cmp Función que compara dos Items
		 *
		 *@return true si se encontro la información en la DLL, en caso contrario retorna false
		 */
		bool Search(Item _key,bool(*cmp)(Item,Item));

		/**
		 *@brief Método que recorre toda la DLL
		 *
		 *@param Función que puede manejar un Item
		 *
		 */
		void Traverse(void(*pfun)(Item));
};

//============Métodos privados=============
template<class Item>
Node<Item>::Node(Item _data){
	data = _data;
	next = NULL;
	prev = NULL;
}

template <class Item>
void DLL<Item>::reset(){
	first = last = cursor = NULL;
	len = 0;
}

//========================================

template <class Item>
DLL<Item>::DLL(){
	reset();
}

template <class Item>
DLL<Item>::~DLL(){
	MakeEmpty();
}

template <class Item>
bool DLL<Item>::InsertBack(Item _data){
	bool done = false;

	/*Creación del nodo a insertar en la DLL*/
	Node<Item>* n = new Node<Item>(_data);

	/*Se verifica que se haya creado bien el nodo*/
	if(n){
		done = true;

		/*Inserta el nodo a la DLL*/
		if(IsEmpty()){
			first = last = cursor = n;
			len = 1;
		}else{
			last -> next = n;
			n -> prev = last;
			last = n;
			len++;
		}

	}

	return done;
}

template <class Item>
bool DLL<Item>::InsertFront(Item _data){
	bool done = false;

	/*Creación del nodo a insertar en la DLL*/
	Node<Item>* n = new Node<Item>(_data);

	/*Se verifica que se haya creado bien el nodo*/
	if(n){
		done = true;

		/*Inserta el nodo en la DLL*/
		if(IsEmpty()){
			first = last = cursor = n;
			len = 1;
		}else{
			n -> next = first;
			first -> prev = n;
			first = n;
			len++;
		}
	}

	return done;

}
template <class Item>
bool DLL<Item>::InsertAfter(Item _data){
	bool done = false;


	if(IsEmpty() || cursor == last){
		done = InsertBack(_data);
	}else{

		/*Creación del nodo a insertar en la DLL*/
		Node<Item>* n = new Node<Item>(_data);

		/*Se verifica que se haya creado bien el nodo*/
		if(n){
			done = true;

			/*Inserta el nodo*/
			n -> next = cursor -> next;
			cursor -> next -> prev = n;
			cursor -> next = n;
			n -> prev = cursor;
			len++;
		}
	}

	return done;
}

template <class Item>
bool DLL<Item>::InsertBefore(Item _data){
	bool done = false;

	if(IsEmpty() || cursor == first){
		done = InsertFront(_data);
	}else{

		/*Creación del nodo a insertar en la DLL*/
		Node<Item>* n = new Node<Item>(_data);

		/*Se verifica que se haya creado bien el nodo*/
		if(n){
			done = true;

			/*Inserta el nodo*/
			n -> prev = cursor -> prev;
			cursor -> prev -> next = n;
			cursor -> prev = n;
			n -> next = cursor;
			len++;
		}
	}

	return done;

}

template <class Item>
bool DLL<Item>::Remove(Item* _data_back){
	bool done = false;

	if(!IsEmpty() && NULL != cursor){
		done = true;

		if(cursor == first){
			RemoveFront(_data_back);
		}else if(cursor == last){
			RemoveBack(_data_back);
		}else{

			/*Se guarda la información del nodo*/
			*_data_back = cursor -> data;

			/*Se guardan el nodo anterior al cursor*/
			Node<Item>* left = cursor -> prev;

			/*Se guarda el nodo siguiente al cursor*/
			Node<Item>* right = cursor -> next;

			/*Se elimina el nodo al que apunta el cursor*/
			delete cursor;

			if(left == NULL && right == NULL){
				reset();
			}else{

				/*Se vuelven a enlazar los nodos*/
				cursor = left;
				cursor -> next = right;
				right -> prev = cursor;
				len--;
			}
		}
	}

	return done;

}

template <class Item>
bool DLL<Item>::RemoveFront(Item* _data_back){
	bool done = false;

	if(!IsEmpty()){
		done = true;

		/*Se guarda la información del nodo*/
		*_data_back = first -> data;

		/*Se elimina el primer nodo de la DLL*/
		Node<Item>* tmp = first -> next;
		delete first;
		first = tmp;

		if(NULL != first){
			first -> prev = NULL;
			len--;
		}else{
			reset();
		}
	}

	return done;

}

template <class Item>
bool DLL<Item>::RemoveBack(Item* _data_back){
	bool done = false;

	if(!IsEmpty()){
		done = true;

		/*Se guarda la información del nodo*/
		*_data_back = last -> data;

		/*Se elimina el ultimo nodo de la DLL*/
		Node<Item>* tmp = last -> prev;
		delete last;
		last = tmp;

		if(NULL != last){
			last -> next = NULL;
			len--;
		}else{
			reset();
		}
	}

	return done;
}

template <class Item>
bool DLL<Item>::RemoveAfter(Item* _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != last && cursor != NULL){
		done = true;

		/*Se guarda el nodo siguiente al cursor*/
		Node<Item>* tmp1 = cursor -> next;

		/*Se guarda la información del nodo*/
		*_data_back = tmp1 -> data;

		/*Se guarda el nodo siguiente al que se elimianra*/
		Node<Item>* tmp2 = tmp1 -> next;

		/*Se elimina el nodo siguiente al cursor*/
		delete tmp1;

		/*Se acomodan los nodos*/
		cursor -> next = tmp2;

		if(tmp2 != NULL){
			tmp2 -> prev = cursor;
		}else{
			last = cursor;
		}
		len--;
	}

	return done;
}

template <class Item>
bool DLL<Item>::RemoveBefore(Item* _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != first && cursor != NULL){
		done = true;

		/*Se guarda el nodo anterior al cursor*/
		Node<Item>* tmp1 = cursor -> prev;

		/*Se guarda la información del nodo*/
		*_data_back = tmp1 -> data;

		/*Se guarda el nodo anterior al nodo que se eliminara*/
		Node<Item>* tmp2 = tmp1 -> prev;

		/*Se elimina el nodo anterior al cursor*/
		delete tmp1;

		/*Se acomodan los nodos*/
		cursor -> prev = tmp2;

		if(tmp2 != NULL){
			tmp2 -> next = cursor;
		}else{
			first = cursor;
		}
		len--;
	}

	return done;
}

template <class Item>
size_t DLL<Item>::Len(){
	return len;
}

template <class Item>
bool DLL<Item>::IsEmpty(){
	return first == NULL;
}

template <class Item>
void DLL<Item>::MakeEmpty(){
	while(NULL != first){

		/*Se guarda el nodo siguiente al primer nodo en la DLL*/
		Node<Item>* tmp = first -> next;

		/*Se elimian el primer nodo en la DLL*/
		delete first;

		/*Se redefine el primer nodo de la DLL*/
		first = tmp;
	}

	reset();
}

template <class Item>
bool DLL<Item>::Peek(Item* _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != NULL){

		/*Se crea una copia de la información del nodo*/
		*_data_back = cursor -> data;
		done = true;
	}

	return done;

}

template <class Item>
void DLL<Item>::CursorFirst(){
	cursor = first;
}

template <class Item>
void DLL<Item>::CursorLast(){
	cursor = last;
}

template <class Item>
void DLL<Item>::CursorNext(){
	if(cursor != NULL){
		cursor = cursor -> next;
	}
}

template <class Item>
void DLL<Item>::CursorPrev(){
	if(cursor != NULL){
		cursor = cursor -> prev;
	}
}

template <class Item>
bool DLL<Item>::FindIf(Item _key, bool(*cmp)(Item,Item)){
	bool found = false;

	for(Node<Item>* it = first; it != NULL; it = it -> next){

		/*Se llama a la función que compara Items*/
		if(cmp(_key, it -> data)){
			found = true;
			break;
		}
	}

	return found;
}

template <class Item>
bool DLL<Item>::Search(Item _key, bool (*cmp)(Item,Item)){
	bool found = false;

	for(Node<Item>* it = first; it != NULL; it = it -> next){

		/*Se llama a la función que compara Items*/
		if(cmp(_key, it -> data)){
			found = true;
			cursor = it;
			break;
		}
	
	}

	return found;
}

template <class Item>
void DLL<Item>::Traverse(void (*pfun)(Item)){

	for(Node<Item>* it = first; it != NULL; it = it -> next){

		/*Se manda la información del nodo a la función que maneja Items*/
		pfun(it -> data);
	}
}

#endif