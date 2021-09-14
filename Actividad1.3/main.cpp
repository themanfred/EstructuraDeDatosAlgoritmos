#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//incluir archivos .h
#include "Bitacora.h"

using namespace std;

//inicializar funciones
int Particion(vector<Bitacora> &v, int inicio, int fin);
void quickSort(vector<Bitacora> &v, int inicio, int fin);
int busquedaBinaria(vector<Bitacora> list, int data);

int main()
{
  //Se crea un vector bitacora
  vector<Bitacora> bitacora;
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
      bitacora.push_back(temp); //Agregar al vector
      cont++;
  }
  fileIn.close();
    

//2. Ordene la información por fecha para la realización de las búsquedas.
  

  //
 

  // Ordenar el vector bitacora mediante el algortmo de ordenamiento quick sort
  quickSort(bitacora, 0, bitacora.size() - 1);

  //cout << "=========================================" << endl;
	/*
  organizar la bitacora en orden cronologico (se puede visualizar esta pruba con este cout), pero se lo comentariza dado que es 
  
  // Mostrar el vector ordenado
  for (int i = 0; i < bitacora.size(); i++)
  {
    cout << i << " >> " << bitacora[i].month << " " << bitacora[i].day << " " << bitacora[i].time << " " << bitacora[i].ip << " " << bitacora[i].message << endl;
    //cout << bitacora[i].key << endl;
    }
	*/
  cout << "=========================================" << endl;
  //inizializar variables mes,dia, hora (fin, inicio)
  string mesInicio;
  string mesFin;
  int diaInicio;
  int diaFin;
  string horaInicio;
  string horaFin;

  //cin y cout de fecha inicial
  cout << "Fecha inicial de busqueda" << endl;
  cout << "Mes Inicio (ej: 01, 10):" << endl;
  cin >> mesInicio;
  cout << "Día Inicio (ej: 01, 31): " << endl;
  cin >> diaInicio;
  cout << "Hora inicial de Busqueda (HH:MM:SS)" << endl;
  cin >> horaInicio;
  //Se crea un objeto y se le asignan los atributos 
  Bitacora fInicio;
  fInicio.month = mesInicio;
  fInicio.day = diaInicio;
  fInicio.time = horaInicio;
  //Se crea un key por medio de los atributos
  fInicio.key = fInicio.createKey();
  cout << "Key Fecha inicial: " << fInicio.key << endl;

  cout << "-----------------------------------------" << endl;


  //cin y cout de fecha final
  cout << "Fecha final de busqueda" << endl;
  cout << "Mes Fin:" << endl;
  cin >> mesFin;
  cout << "Día Fin: " << endl;
  cin >> diaFin; 
  cout << "Hora final de Busqueda (HH:MM:SS)" << endl;
  cin >> horaFin;
  
  //Se crea un objeto y se le asignan los atributos 
  Bitacora fFinal;
  fFinal.month = mesFin;
  fFinal.day = diaFin;
  fFinal.time = horaFin;
  //Se crea un key por medio de los atributos
  fFinal.key = fFinal.createKey();
  cout << "Key Fecha final: " << fFinal.key << endl;
  cout << endl;
  cout << "-----------------------------------------" << endl;
  
  //Se busca por medio del metodo binario los indices de los objetos inicial y final en el vector
  int iInicial = busquedaBinaria(bitacora, fInicio.key) + 1;
  int iFinal = busquedaBinaria(bitacora, fFinal.key) - 1;
  //Se imprimen indices final e inicial
  cout << "Indice inicial: "<< iInicial << endl;
  cout << "Indice final: "<< iFinal << endl;

  //Se muestran los resultados de los datos dentro del rango de busqueda
  cout << "-----------------------------------------" << endl;
	cout << "RESULTADOS " << endl;
	cout << "Desde: " << fInicio.month << " " << fInicio.day << " " << fInicio.time << endl;
	cout << "Hasta: " << fFinal.month << " " << fFinal.day << " " << fFinal.time << endl;
  //Se implementa ciclo for para imprimir todos los datos dentro del rango de indices
    for(int i=iInicial; i<=iFinal; i++){
        cout << bitacora[i].month << " " << bitacora[i].day << " " << bitacora[i].time << " " << bitacora[i].ip << " " << bitacora[i].message << endl;
	}
    cout << "-----------------------------------------" << endl;
	cout << "Archivo \"BitacoraOutput.txt\" generado con exito" << endl;

  //Se crea un archivo output que muestra los resultados dentro del rango, por medio de un ciclo for igual al que se utilizo para imprimirlos
	ofstream fileOut("BitacoraOutput.txt");
	fileOut << "RESULTADOS " << endl;
	fileOut << "---------------------------------------------------"<< endl;
	fileOut << "Fecha Inicial: " << fInicio.month << " " << fInicio.day << " " << fInicio.time << endl;
	fileOut << "Fecha Final: " << fFinal.month << " " << fFinal.day << " " << fFinal.time << endl;
	fileOut << "---------------------------------------------------"<< endl;
	for(int i = iInicial; i <= iFinal; i++){
		fileOut << bitacora[i].month << " " << bitacora[i].day << " " << bitacora[i].time << " " << bitacora[i].ip << " " << bitacora[i].message << endl;
	}
	fileOut.close();

    return 0;
}


//Fun Particion que es llamada
int Particion(vector<Bitacora> &v, int inicio, int fin)
{ 
  int mitad = fin;
  int j = inicio;
  for (int i = inicio; i < fin; ++i)
  {
    //si el key en el inidice actual es menor al del medio
    if (v[i] < v[mitad])
      {
        //swap  con el incial
        swap(v[i], v[j]);
        ++j;
      }
  }
  //swap con el de la mitad
  swap(v[j], v[mitad]);
  return j;
}



void quickSort(vector<Bitacora> &v, int inicio, int fin)
{
  if (inicio < fin)
  {
    int p = Particion(v, inicio, fin);
    quickSort(v, inicio, p - 1);
    quickSort(v, p + 1, fin);
  }
}

int busquedaBinaria(vector<Bitacora> list, int data) {
  int izquierda = 0;
  int derecha = list.size() - 1;
  int mid;
  while (izquierda <= derecha) {
    // Calcular el punto medio
    mid = (izquierda + derecha) / 2;
    
    //Compara si el dato del medio es igual al dato considerado
    if (list[mid].key == data) {
      // Retorna la posicion mid
      return mid;
    } else {
      // Comparacion que determina si el dato es menor al del medio de la lista
      if (data < list[mid].key) {
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
