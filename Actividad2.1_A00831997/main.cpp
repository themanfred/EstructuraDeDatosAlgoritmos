//Thomas Freund Paternostro
//A00831997
//Implementación de un ADT de estructura de datos lineales

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

using namespace std;

void create(int data ,LinkedList<int> list);
void update(int data ,LinkedList<int> list,int updateValue );
void read(int data ,LinkedList<int> list);
void del(int data ,LinkedList<int>  list);



int main(){
    
  //crear estructura linkedlist de data tipo int
  LinkedList<int> list;
  int data, index; // variable data y index tipo int
  int updateValue; // valor actualizado usando funcion update
  string fileName = " ", s; // 
  int  num;
  bool fileNameF =0;
  string opcion;

  while( fileNameF == 0){
     cout << "Nombre del archivo(Opciones: 1.in, 2.in, 3.in):" << endl;
     cin >> fileName;
      if(fileName == "1.in" || fileName == "2.in" || fileName == "3.in" ){
        fileNameF = 1;
      }
      else{
        fileNameF =0;
      }
  }
  
  
  //leer archivo
	ifstream in;
	in.open(fileName);
  while(in >> s){
    num = stoi(s);
		list.create(num);

  }

  in.close();
	list.print();
	cout << endl;
  

  do{
    cout<< "\t------------MENU------------\t"<<endl;
    cout<<" 1) Create"<<endl;
    cout<<" 2) Read"<<endl;
    cout<<" 3) Update"<<endl;
    cout<<" 4) Delete"<<endl;
    cout<<" 5) Salir"<<endl;

    cin>> opcion;
    if(opcion == "1"){
      //create
      list.print();
      create(data ,list);
	    cout << endl;
    }else if(opcion == "2"){
      //read
      list.print();
      read(data ,list);
	    cout << endl;
    }else if(opcion == "3"){
      //update
      list.print();
      cout<<endl;
      cout << "Que valor desea actualizar?: " << endl;
	    cin >> data;
      update( data,  list, updateValue );
      cout << endl;
    }else if(opcion == "4"){
      //delete
      list.print();
      cout<<endl;
      del( data , list);
      cout << endl;
     }else if(opcion == "5"){
      //delete
      cout << "Hasta luego"<< endl;

    }else{
      cout<< "El valor no es una opcion valida. Digite denuevo el valor." <<endl;

    }

  }while(opcion != "5");

    return 0;
}



void update(int data, LinkedList<int> list,int updateValue ){
	cout << endl;
	if (list.read(data) != 0){
    	cout << "Valor encontrado, por cual valor lo desea sustituir? " << endl,
    	cin >> updateValue;
    	list.update(data, updateValue);
      
  }
  else{
    cout << "Valor no encontrado " << endl;
  }

  list.print();
	cout << endl;
}

void read(int data ,LinkedList<int> list){
  cout<< endl;
  cout << "Cual es el numero que deseas buscar: " << endl;
  cin >> data;
  
  if (list.read(data) != 0){
    cout << "Elemento encontrado!" << endl;
	} else {
		cout << "El elemento no fue encontrado." << endl;
	}
}

void del(int data ,LinkedList<int> list){
  cout<< endl;
	cout << "Que valor de la lista deseas eliminar " << endl;
	cin >> data;
	if (list.read(data) != 0){
    	list.del(data);
    	cout << "Elemento encontrado y eliminado." << endl;
      cout << "La nueva lista sin el valor " << data<< " es: " << endl;
      list.print();
    	
	} else {
		cout << "El elemento que desea eliminar no fue encontrado." << endl;
	}
	
	cout << endl;
}


void create(int data ,LinkedList<int> list){
  cout<< endl;
  cout << "Que valor deseas agregar: " ;
  cin >> data;
  list.create(data);
  list.print(); 
  cout << endl;
}
