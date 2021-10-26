
#ifndef Node_h
#define Node_h

template<class T>
class Node{
    private:
        T data;
        Node *next;
        Node *prev;
    public:
        Node(T data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
        Node(T data, Node *prev, Node *next){
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
        T getData(){
            return this->data;
        }
        Node* getPrev(){
            return this->prev;
        }
        Node* getNext(){
            return this->next;
        }
        void setData(T data){
            this->data = data;
        }
        void setPrev(Node *prev){
            this->prev = prev;
        }
        void setNext(Node *next){
            this->next = next;
        }
};


#endif

