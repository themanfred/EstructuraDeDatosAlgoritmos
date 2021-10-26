#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//incluir archivos .h
#include "Bitacora.h"
#include "LinkedList.h"

using namespace std;

//inicializar funciones
int Particion(LinkedList<Bitacora> &v, int inicio, int fin);
void quickSort(LinkedList<Bitacora> &v, int inicio, int fin);
int busquedaBinaria(vector<Bitacora> &bitacoras, IP ipABuscar);
Node<Bitacora>* buscarPorIPSecuencial(LinkedList<Bitacora> &bitacoras, IP ipABuscar, bool buscarDesdeFinal);

int main()
{
  //Se crea un LinkedList bitacora
  LinkedList<Bitacora> bitacora;
  // ifstream -> Input file Stream
  ifstream fileIn("Bitacora.txt");
  string line; //Inizializar lectura de linea
  string word; //Inizializar lectura de palabra
  char delim = ' '; //Inizializar char de delim
  string monthS, time, ip, message, month; // variables leidas en el archivo
  int day; // variable int dia leido en el archivo
  int cont = 0;
  while (getline(fileIn, line)) //lee el archivo 
    {
     // string object with a stream allowing us to read from the string as if it were a stream 
      stringstream ss(line);
      ss >> monthS >> day >> time >> ip >> message;
      while (ss >> word)
      {
          message = message + " " + word;
      }
        
      Bitacora temp(monthS, day, time, ip, message);
      bitacora.addLast(temp); //Agregar a la LinkedList
      cont++;
  }
  fileIn.close();
    

//2. Ordene la información por fecha para la realización de las búsquedas.
 
  // Ordenar la LinkedList bitacora mediante el algortmo de ordenamiento quick sort
  quickSort(bitacora, 0, bitacora.getSize() - 1);

  cout << "=========================================" << endl;

  //cin y cout de IP inicial
  string ipInicialString;
  cout << "IP inicial de busqueda" << endl;
  cin >> ipInicialString;
  //Se crea un objeto
  IP ipInicial(ipInicialString);

  cout << "-----------------------------------------" << endl;

  //cin y cout de IP final
  string ipFinalString;
  cout << "IP final de busqueda" << endl;
  cin >> ipFinalString;
  
  //Se crea un objeto
  IP ipFinal(ipFinalString);
  
  //Se busca la ip inicial a imprimir
  Node<Bitacora>* iInicial = buscarPorIPSecuencial(bitacora, ipInicial, false);

  //Se muestran los resultados de los datos dentro del rango de busqueda
  cout << "-----------------------------------------" << endl;
	cout << "RESULTADOS " << endl;
	cout << "Desde: " << ipInicialString << endl;
	cout << "Hasta: " << ipFinalString << endl;

  //Se crea un archivo output que muestra los resultados dentro del rango, por medio de un ciclo for igual al que se utilizo para imprimirlos
	ofstream fileOut("BitacoraOutput.txt");
	fileOut << "RESULTADOS " << endl;
	fileOut << "---------------------------------------------------"<< endl;
	fileOut << "IP Inicial: " << ipInicialString << endl;
	fileOut << "IP Final: " << ipFinalString << endl;
	fileOut << "---------------------------------------------------"<< endl;

  //Se implementa ciclo for para imprimir y guardar todos los datos dentro del rango de indices
    while(iInicial != nullptr && iInicial->getData().ip <= ipFinal){
        cout << iInicial->getData().month << " " << iInicial->getData().day << " " 
		<< iInicial->getData().time << " " << iInicial->getData().stringIP << " " 
		<< iInicial->getData().message << endl;
		
		fileOut << iInicial->getData().month << " " << iInicial->getData().day << " " 
		<< iInicial->getData().time << " " << iInicial->getData().stringIP << " " 
		<< iInicial->getData().message << endl;

		iInicial = iInicial->getNext();
	}
    cout << "-----------------------------------------" << endl;
	cout << "Archivo \"BitacoraOutput.txt\" generado con exito" << endl;
	fileOut.close();

    return 0;
}

template <class T>
void swapNodeData(Node<T>* first, Node<T>* second) {
	T firstNodeData = first->getData();
	first->setData(second->getData());
	second->setData(firstNodeData);
}


//Fun Particion que es llamada
int Particion(LinkedList<Bitacora> &v, int inicio, int fin)
{ 
    int j = inicio;

	Node<Bitacora>* nodeAtI = v.getSpecificNode(inicio);
	Node<Bitacora>* nodeAtMitad = v.getSpecificNode(fin);
	Node<Bitacora>* nodeAtJ = nodeAtI;
  
  for (int i = inicio; i < fin; ++i)
  {
    //si la IP del índice actual es menor a la del medio
    if (nodeAtI->getData() < nodeAtMitad->getData())
      {
        //swap con el incial
        swapNodeData(nodeAtI, nodeAtJ);
        ++j;
		nodeAtJ = nodeAtJ->getNext();
      }

	nodeAtI = nodeAtI->getNext();
  }
  //swap con el de la mitad
  swapNodeData(nodeAtJ, nodeAtMitad);
  return j;
}

void quickSort(LinkedList<Bitacora> &v, int inicio, int fin)
{
  if (inicio < fin)
  {
    int p = Particion(v, inicio, fin);
    quickSort(v, inicio, p - 1);
    quickSort(v, p + 1, fin);
  }
}


//Dado que ahora estamos trabajando con un LinkedList que tiene cabeza y
//cola, no es eficiente andar obteniendo valores medios, por lo que no 
//se utilizará busquedaBinaria, sino busquedaSecuencial
//Pusimos la opción de "empezarDesdeFinal" puesto que no es eficiente, al buscar el índice
//final, buscar desde el comienzo de la lista, dado que sabemos que desde i=0 hasta i=indiceInicial
//no está el valor que estamos buscando.
Node<Bitacora>* buscarPorIPSecuencial(LinkedList<Bitacora>& bitacoras, IP ipABuscar, bool empezarDesdeFinal){
	Node<Bitacora>* current = empezarDesdeFinal ? bitacoras.getTail() : bitacoras.getHead();
	int i = empezarDesdeFinal ? bitacoras.getSize()-1 : 0;

	if(empezarDesdeFinal){
		while(current != nullptr){
			if(current->getData().ip <= ipABuscar){
				return current;
			}
			i--;
			current = current->getPrev();
		}
	} else {
		while(current != nullptr){
			if(current->getData().ip >= ipABuscar){
				return current;
			}
			i++;
			current = current->getNext();
		}
	}
	return nullptr;
}

//Dado que ahora estamos trabajando con un LinkedList que tiene cabeza y
//cola, no es eficiente andar obteniendo valores medios, por lo que no 
//se utilizará busquedaBinaria, sino busquedaSecuencial
int busquedaBinaria(vector<Bitacora>& bitacoras, IP ipABuscar) {
  int izquierda = 0;
  int derecha = bitacoras.size() - 1;
  int mid;
  while (izquierda <= derecha) {
    // Calcular el punto medio
    mid = (izquierda + derecha) / 2;
    
    //Compara si el dato del medio es igual al dato considerado
    if (bitacoras[mid].ip == ipABuscar) {
      // Retorna la posicion mid
      return mid;
    } else {
      // Comparacion que determina si el dato es menor al del medio de la lista
      if (ipABuscar < bitacoras[mid].ip) {
        //Cambio de limite derecho a mid menos uno
        derecha = mid - 1;
      } else {
        //Cambio de limite izquierdo a mid mas uno
        izquierda = mid + 1;
      }
    }
  }
  return mid;
}
