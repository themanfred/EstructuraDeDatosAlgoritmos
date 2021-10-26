//Thomas Freund 
//A00831997
#include <iostream>
#include "priority_queue.h"

using namespace std;

int main() {

  priority_queue list1;

  int A[10]= {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};
  int B[10]= {12,2,4,1,32,421,4,2,41,1};

  for(int i=0;  i < 10;  i++){
    list1.push(B[i]);
    //list2.push(B[i]);
  }
  list1.print();
  //list2.print();

  cout<< "Verificar si esta vacia la  lista 1: "<<endl;
  if (list1.empty() ==1){
    cout<<"Esta vacia"<<endl;
  }else{
    cout<<"No esta vacia"<<endl;
  }
  /*
  cout<< "Verificar si esta vacia la  lista 2: "<<endl;
  if (list2.empty() ==1){
    cout<<"Esta vacia"<<endl;
  }else{
    cout<<"No esta vacia"<<endl;
  }*/
  cout<<endl;
  cout<< "Tamaño de la lista 1: "<< list1.size()<<endl;
  //cout<< "Tamaño de la lista 2: "<< list2.size()<< endl;

  for( int i=0; i<10; i++){
    cout<<"El top de la lista 1 es:"<< list1.top()<<endl;
    list1.pop();
    list1.print();
    cout<<endl;
    //cout<<"El top de la lista 2 es:"<< list2.top()<<endl;
    //list2.pop();
    //cout<<endl;

  }
  cout<< "Verificar si esta vacia la  lista 1: "<<endl;
  if (list1.empty() ==1){
    cout<<"Esta vacia"<<endl;
  }else{
    cout<<"No esta vacia"<<endl;
  }

}