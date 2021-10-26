#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "BST.h"

using namespace std;

int particion(vector<IP> &v, int inicio, int fin);
void quickSort(vector<IP> &v, int inicio, int fin);

int main(){
    //Solo guardaremos las IPs ya que son lo único relevante para resolver este problema
    vector<IP> ips;
    ifstream bitacoraFile("bitacora2.txt");
    string currentLine;

    //Obtenemos la IP de cada línea de la bitácora
    while(getline(bitacoraFile, currentLine)){
        stringstream currLineStream(currentLine);
        string unused;
        string ip;
        currLineStream >> unused >> unused >> unused >> ip;
        ips.push_back(IP(ip));
    }

    //Ahora ordenamos las IPs usando QuickSort
    quickSort(ips, 0, ips.size()-1);

    //Ahora creamos el BST, donde:
    //Key: número de repeticiones
    //Value: IPs que se repiten ese número de veces
    BST repeticiones;

    //Vamos populando el BST:
    int eqIPCount; //Equal IP Count
    IP prevIP;

    for(IP ip : ips){
        if(prevIP != ip){
            if(prevIP != IP())
                repeticiones.addIPToAccessNum(prevIP, eqIPCount);
            eqIPCount = 1;
        } else {
            eqIPCount++;
        }
        prevIP = ip;
    }

    //Imprimimos las repeticiones de cada dirección IP
    repeticiones.visit(5);

    //Imprimimos las 5 IPs con más accesos
    cout << "5 IPs con mas accesos: " << endl;
    repeticiones.printXIPsWithMoreAccesses(5);
    cout << endl;

    return 0;
}

int particion(vector<IP> &v, int inicio, int fin)
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



void quickSort(vector<IP> &v, int inicio, int fin)
{
  if (inicio < fin)
  {
    int p = particion(v, inicio, fin);
    quickSort(v, inicio, p - 1);
    quickSort(v, p + 1, fin);
  }
}