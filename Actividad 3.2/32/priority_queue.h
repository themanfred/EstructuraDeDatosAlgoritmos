//Thomas Freund 
//A00831997
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class priority_queue{
	public:
		priority_queue();
		void push(int dato); 
		void pop(); 			
		int top(); 
		bool empty();
		int size();
		void print();
    void maxHeapify(int index);
	private:	
		vector<int> datos;
};

//inicializacion 
priority_queue::priority_queue(){
   datos.push_back(0);
}

//Agregue un dato a la fila priorizada (insert)
void priority_queue::push(int dato){
  //insertar el dato en el queue
  datos.push_back(dato);
  //establecer un index
  int index = datos.size()-1;
  //seguier mientras no sea 1
  while(index != 1)
  {
    //si el elemento es mayor que dato con ese index, swap
  if(datos[index] > datos[index >> 1])
  {
  swap(datos[index], datos[index >> 1]);
  index >>= 1;
  }
  else break;
}}


//Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
int priority_queue::top(){
  return datos[1];
}

//Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
bool priority_queue::empty(){
  //si el size regresa un valor que no es cero, no esta vacio
  if (datos.size() == 0){
    return true;
  }else{
  return false;
  }
}

//Regresa la cantidad de datos que tiene la fila priorizada
int priority_queue::size(){
  return datos.size()-1;
}

//imprimir
void priority_queue::print(){
  for (int i=1; i<datos.size(); i++){
		cout << datos[i] << " ";
	}
	cout << endl;
}

//Saca de la fila priorizada el dato que tiene mayor prioridad
void priority_queue::pop(){

  if(datos.size() == 1){
    return;
  }
  swap(datos[1], datos[datos.size()-1]);
  datos.pop_back();
  maxHeapify(1);//llama al actual top y determina la estructura para tener maxHeap
}

//explicado en clase
void priority_queue::maxHeapify(int index){
  while(index < datos.size())
        {
    int largest = index;
    if((index << 1) < datos.size() && datos[index << 1] > datos[largest]){
    largest = index << 1;
    }
    if((index << 1) + 1 < datos.size() && datos[(index << 1) + 1] > datos[largest]){
    largest = (index << 1) + 1;
    }
    if(largest != index)
    {
    swap(datos[index], datos[largest]);
    index = largest;
    }
    else break;
  }
}