template<class T>
class Node{
    private:
        T data; //
        Node<T> *next;//
    public:
        Node(T data);
        Node(T data, Node<T> *next);
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T>* next);//variable void  
};
//inicializar template Node<T>
template <class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr; // NULL 
}
//inicializar template Node<T> con variables 
template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}
//getData
template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T> * Node<T>::getNext(){
    return this->next;
}

//Setters


//setData
template <class T>
void Node<T>::setData(T data){
    this->data = data;
}
//SetNext
template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}





