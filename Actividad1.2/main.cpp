// Nombre: Thomas Freund Paternostro
// Matricula: A00831997

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//inicializar funciones 
void swap(int a[], int i, int j);
void merge(int a[], int inicio, int mitad, int fin);
void ordenaMerge(int a[], int inicio, int fin);
void ordenaBurbuja(int a[], int n);
void ordenaIntercambio(int arreglo[], int n);
long int busqSecuencial(int arreglo[], int n, int dato);
long int busqBinaria(int arreglo[], int min, int max, int dato);


//inicializar main
int main(){

  //variables globales
	int  numeroDeBusqueda, rep;
	string s;
	int n, j, i;

  //variable archivo
	string archivo;
	cout << "Nombre del archivo (Opciones: 01.in, 02.in, 03.in, 04.in):" << endl;
	cin >> archivo;//leer string 
	
  // ifstream -> Input file Stream
	ifstream in(archivo);
	getline(in,s);
	n = stoi(s);
  //arreglo con puntero
	int *arr = new int[n];
  int *arrB = new int[n];
	int *arrM = new int[n];
	int *arrI = new int[n];
	
	i = 0;
	
  //pasar a cada arreglo la linea leida
  //son diferentes arreglos ya que son modificados dependiendo de su algoritmo.
	while(getline(in,s)){
		arr[i] = stoi(s);
    arrB[i] = stoi(s);
		arrM[i] = stoi(s);
		arrI[i] = stoi(s);
		
		i++;
	}
	
	in.close();
	
  //Desde la aplicación deberá solicitar al usuario la cantidad de búsquedas que desea
	cout << "Cuantos numeroDeBusquedas deseas buscar en el arreglo?" << endl;
	cin >> rep;
	j = 0;
	ofstream out;
	out.open("output.txt",ios::out);
		
	while (j < rep){
    //por cada búsqueda deberá de solicitar el número que desea buscar y desplegará el índice donde se encuentra localizado o -1
		cout << "Cual es el numero que quieres buscar en el arreglo:" << endl;
		cin >> numeroDeBusqueda;
		
    //imprimir resultados
		cout << "Indice por busqueda secuencial: " << busqSecuencial(arr, n, numeroDeBusqueda) << endl;

		cout << "--------------------------" << endl;

    ordenaBurbuja(arrB, n);
		cout << "Indice por ordenamiento de burbuja y binaria: " << busqBinaria(arrB,0,n,numeroDeBusqueda) << endl;

		cout << "--------------------------" << endl;

		ordenaMerge(arrM, 0, n-1);
		cout << "Indice por ordenamiento merge y binario : " << busqBinaria(arrM,0,n,numeroDeBusqueda) << endl;
		
		cout << "--------------------------" << endl;

		ordenaIntercambio(arrI, n);
		cout << "Indice por ordenamiento de intercambio y binario: " << busqBinaria(arrI,0,n,numeroDeBusqueda) << endl;
			
    cout << "--------------------------" << endl;
		
		j++;
		
	}
	
	out.close();
	
	return 0;
}

//cambia un valor almazenado por otro en otro indice del arreglo
void swap(int a[], int i, int j){
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

//Metdo menos eficiente, hace todos los cambios posibles n^2
void ordenaBurbuja(int a[], int n) {
	int aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j + 1]) {
				aux = a[j+1];
				a[j + 1] = a[j];
				a[j] = aux;
			}
		}
	}
}

//Divide y venceras. Se modifica la secuencia y se unen diferentes mitades  hasta completar la secuencia
void merge(int a[], int inicio, int mitad, int fin){
	int i = inicio, j = mitad + 1, k = 0, aux[fin - inicio + 1];
	
	while (i <= mitad && j <= fin){
		if (a[i] < a[j]){
			aux[k] = a[i];
			i++;
		} else {
			aux[k] = a[j];
			j++;
		}
		k++;		
	}
	
  while (i <= mitad){
    aux[k] = a[i];
    k++;
    i++;
  }

    
  while (j <= fin){
    aux[k] = a[j];
    k++;
    j++;
  }

    
  for (i = inicio; i <= fin; i++){
    a[i] = aux[i - inicio];
  }
    
}
// Algoritmo que uso recursion llamando a merge para poder secuenciar y ordenar. Divide y venceras.
void ordenaMerge(int a[], int inicio, int fin){
	
	int mitad;
	if(inicio < fin){
		
		mitad = (inicio + (fin - 1)) / 2;
		ordenaMerge(a,inicio,mitad);
		ordenaMerge(a,mitad+1,fin);
		merge(a,inicio,mitad,fin);
		
	}
}

// ordena llamando a la funcion swap donde se cambia el unonpor otro si ve que uno es menor que el siguinete. Hacer eso por cada indice j y por cada posicion de ese respectivo indice i
void ordenaIntercambio(int arreglo[], int n){
	int i, j, aux;
	for (i=0 ; i <= n-2 ; i++){
		for (j=i+1 ; j <= n-1 ; j++){
			if (arreglo[j]<arreglo[i]){
				swap(arreglo,i,j);
			}
		}
	}
	
}
//Va uno por uno y si el dato esta en algun indice imprime el indice
long int busqSecuencial(int arreglo[], int n, int dato){
    for(int i = 0; i < n; i++){
        if(arreglo[i] == dato){
            return i;
        }
    }
    return -1;
}

//La búsqueda binaria utiliza la recursion  donde el valor mínimo y máximo se está aproximando a uno exacto que es el que se está buscando que en este caso es el key
long int busqBinaria(int arreglo[], int min, int max, int dato){
	int key;
	key = (min+max)/2;
	
    if (dato == arreglo[key]){
    	return key;
	} else if (dato < arreglo[key]){
		max = key - 1;
	} else {
		min = key + 1;
	}
	return busqBinaria(arreglo, min, max, dato);
}