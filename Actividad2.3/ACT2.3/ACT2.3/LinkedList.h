
#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <class T>
class LinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void deleteAll();
        int getSize();
        Node<T> *getHead();
        Node<T> *getTail();
        Node<T> *getSpecificNode(int index);
        void addFirst(T data);
        void addLast(T data);
};


template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *current = head;
    while(head != nullptr){
        head = head->getNext();
        delete current;
        current = head;
    }
    size = 0;
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template <class T>
Node<T> *LinkedList<T>::getHead(){
    return this->head;
}

template <class T>
Node<T> *LinkedList<T>::getTail(){
	return this->tail;
}

//Esta función fue optimizada para que, en caso de que el nodo
//específico esté más cerca al tail que al head, comience a buscar
//desde el tail en lugar de desde el head.
template <class T>
Node<T> *LinkedList<T>::getSpecificNode(int index){
    if(index < (size-1 - index)){
        Node<T>* current = head;
        int i = 0;
        while(current != nullptr){
            if(i == index){
                return current;
            }
            current = current->getNext();
            i++;
        }
    } else {
        Node<T>* current = tail;
        int i = size-1;
        while(current != nullptr){
            if(i == index){
                return current;
            }
            current = current->getPrev();
            i--;
        }
    }

    return nullptr;
}

template <class T>
void LinkedList<T>::addFirst(T data){
    Node<T>* newNode = new Node<T>(data, nullptr, head);
    if(size == 0){
        tail = newNode;
    } else {
        head->setPrev(newNode);
    }
    head = newNode;
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    Node<T>* newNode = new Node<T>(data, tail, nullptr);
    if(size == 0){
        head = newNode;
    } else {
        tail->setNext(newNode);
    }
    tail = newNode;
    size++;
}
#endif



