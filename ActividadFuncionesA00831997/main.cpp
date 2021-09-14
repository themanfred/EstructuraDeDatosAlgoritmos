#include <iostream>
#include <fstream>
#include <string>

using namespace std;

 long sumaRecursiva( long n){
	if(n==0){
		return 0;
	}
	return n + sumaRecursiva(n-1);	
}

long sumaIterativa( long n){
	long sum = 0;
	for(int i=1; i<=n; i++){
		sum += i;
	}
	return sum;
}

long sumaDirecta( long n){
	long sum = 0;
	sum = ((n * (n + 1)) / 2);
	return sum;
}

int main() {
  string s,s2,s3,s4;
  
  //caso prueba #1
  ifstream archivo("test.thomas");
  getline(archivo, s);
  int n = stoi(s);

  cout<<"caso prueba 1"<<endl;
  int *arreglo1 = new int[n];
  int i = 0;
  while(getline(archivo, s)){
    //El numero del arreglo se le da el valor en stoi(s)
    arreglo1[i] = stoi(s);
    //se hace las tres operaciones
    cout << arreglo1[i] << endl;
    cout << "Suma iterativa: "<<sumaIterativa(arreglo1[i]) <<endl;
    cout <<"Suma recursiva:"<< sumaRecursiva(arreglo1[i]) << endl;
    cout <<"Suma directa:"<< sumaDirecta(arreglo1[i]) << endl;
    i++;
  }

   
  

}
