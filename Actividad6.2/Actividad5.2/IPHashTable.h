#include "IPSummary.h"
#include <string>
#include <iostream>
#include <forward_list>
#include <iterator>

#define TABLE_SIZE 65536 //256^2

using namespace std;

class IPHashTable{
    private:
        forward_list<IPSummary> ipSummaries[TABLE_SIZE];
        //Esta es la función hash, que con la IP (el key) determina el índice dentro del arreglo
        int getIPIndex(string ipAsString){
            int octets[2];
            for(int i = 0; i < 2; i++){
                int dotIndex = ipAsString.find('.');
                octets[i] = stoi(ipAsString.substr(0, dotIndex));
                ipAsString = ipAsString.substr(dotIndex+1);
            }

            return octets[0]*256 + octets[1];
        }
    public:
        void addIPAccess(string ipAsString, string accessDate, string failReason){
            int ipIndex = getIPIndex(ipAsString);
            if(ipSummaries[ipIndex].empty()){
                ipSummaries[ipIndex].push_front(IPSummary(ipAsString));
                ipSummaries[ipIndex].front().addAccess(ipAsString, accessDate, failReason);
            } else {
                forward_list<IPSummary>::iterator it = ipSummaries[ipIndex].begin();
                while(it != ipSummaries[ipIndex].end() && !(it->isSameIP(ipAsString))){
                    advance(it, 1);
                }
                if(it == ipSummaries[ipIndex].end()){
                    ipSummaries[ipIndex].push_front(IPSummary(ipAsString));
                    ipSummaries[ipIndex].front().addAccess(ipAsString, accessDate, failReason);
                } else {
                    it->addAccess(ipAsString, accessDate, failReason);
                }
            }
        }

        void printIPSummary(string ipAsString){
            int ipIndex = getIPIndex(ipAsString);
            if(ipSummaries[ipIndex].empty()){
                cout << "La IP seleccionada no tiene accesos" << endl;
            } else {
                forward_list<IPSummary>::iterator it = ipSummaries[ipIndex].begin();
                while(!(it->isSameIP(ipAsString)) && it != ipSummaries[ipIndex].end()){
                    advance(it, 1);
                }
                if(it == ipSummaries[ipIndex].end()){
                    cout << "La IP seleccionada no tiene accesos" << endl;
                } else {
                    it->print();
                }
            }
        }
};