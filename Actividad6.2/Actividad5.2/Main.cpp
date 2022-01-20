#include <iostream>
#include "IPHashTable.h"
#include <sstream>
#include <fstream>

using namespace std;

int main(){
    //Alimentamos los datos dentro del HashTable:
    IPHashTable hTable;
    ifstream bitacora("bitacoraACT5_2.txt");
    string currentLine;
    while(getline(bitacora, currentLine)){
        stringstream clStream(currentLine);
        string mes, dia, hora, ip, razonFalla;
        clStream >> mes >> dia >> hora >> ip;
        getline(clStream, razonFalla);
        razonFalla = razonFalla.substr(1);
        string fecha = mes + " " + dia + " " + hora;
        hTable.addIPAccess(ip, fecha, razonFalla);
    }

    //Le pedimos al usuario la información que necesita:
    string ipSolicitada;
    do{
        cout << "Escribe la direccion IP de la que quieres el resumen (escribe -1 para terminar): ";
        cin >> ipSolicitada;
        cout << endl;
        hTable.printIPSummary(ipSolicitada);
    } while (ipSolicitada != "-1");
    
    return 0;
}