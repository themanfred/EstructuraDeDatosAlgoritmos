#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"

using namespace std;

template <class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
       // ~LinkedList();//Delete
        void print();
        int getSize();
        bool isEmpty();
        void addFirst(T data);
        //CRUD
        void create(T data);
        bool read(T data);
        void update(T data, T updatecurrentValue);
        void del(T data);
       // void deleteAll();
        
        
};

//incicializar template
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

//esta vacio el linkedin list? template
template <class T>
bool LinkedList<T>::isEmpty()
{
  if(size > 0 ){
    return 0;
  }else{
    return 1;
  }
    
}


//print  template
template <class T>
void LinkedList<T>::print(){
	Node<T> *current = head;//asignar tope a la pos actual
  int i=1; //counter
  cout<<"El archivo tiene los siguientes elementos:"<<endl;
	while(current != nullptr){

		cout <<i << ") "<< current->getData() << ", "; //imprimir tope y su indice
		current = current->getNext(); // conseguir el siguiente 
    i++; // sumar al counter de indice

	}
}
	

//template para leer archivo	
template <class T>
bool LinkedList<T>::read(T data){
	Node<T> *current = head;
	T datoActual;
  
	while(current != nullptr){
		datoActual = current -> getData();
        if (data == datoActual){
        	return 1;
		}
		current = current -> getNext();
    }
    return 0;
}



/*
//Delete all template
template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll(); //borra todos los elementos
}
4

//Delete all template
template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *current = head;// pon la posicion incial en el apuntador
    while(head != nullptr){ // si el tope no es nulo continua
        head = head->getNext(); // borra 
        delete current;
        current = head;
    }
    size = 0;
}
*/
//add first template


template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head); // crea un objeto dinaico en el tope
    size++; //incrementa el tam del linked list
}

//create template 
template <class T>
void LinkedList<T>::create(T data){
    
    if(size == 0){
      //llama a add first y crea un objeto
        addFirst(data);
        return; //salimos de la funcion
    }
    Node<T> *aux = head;
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
        size++;
    }
    aux->setNext(new Node<T>(data));
    
    //current->setNext(*aux);
}

template <class T>
void LinkedList<T>::del(T data){
	Node<T> *previous = nullptr;   //empezamos con la pos nula
	Node<T> *current = head; // apuntamos al siguiente como tope
  //mientras que siguiente no sea igual al valor buscado y no este vacio
  while ((current->getData() != data) && (current != nullptr))  {
  	//el anterior tope lo pasamos al siguiente
    previous = current;
    //pasamos el valor del siguiente nodo
    current = current->getNext();
	}

    if(previous == nullptr){ 
      head = head->getNext(); //pasamos la posicion del siguiente al tope
      delete current; // borramos el actual valor
      size--; // reducimos el size del linked list
    } else {
      previous->setNext(current->getNext()); // current apunta al siguiente valor y los establecemos al valor que tendria el proxima. El previo asume esa pos
      delete current; // borramos el actual valor
      size--; // reducimos el size del linked list
    } 
}

template <class T>
void LinkedList<T>::update(T data, T updatecurrentValue){
  T currentValue;
	Node<T> *current = head;
	while(current != nullptr){
		currentValue = current -> getData();
    if (data == currentValue){
      current->setData(updatecurrentValue); //le damos el nuevo valor 
      return; //salimos de la funcion
		}
		current = current -> getNext(); // recorremos la lista
  }
  
}

#endif




