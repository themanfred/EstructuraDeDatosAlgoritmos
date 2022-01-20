#include <string>
#include <fstream>
#include <list>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

//Given an IP, removes its port
void removePort(string& ipWithPort){
    int twoDotsIndex = ipWithPort.find(":");
    ipWithPort = ipWithPort.substr(0, twoDotsIndex);
}

int main(){
    ifstream bitacora("bitacora.txt");
    ofstream output("output.txt");
    int n, m;
    bitacora >> n >> m;

    map<string, int> IPtoID;
    string* IDtoIP = new string[n];

    string currentIP;
    for(int i = 0; i < n; i++){
        bitacora >> currentIP;
        IPtoID.insert({currentIP, i});
        IDtoIP[i] = currentIP;
    }

    list<list<int>> adjList(n);

    string currentLine;
    string currentOriginIP, currentDestinationIP, unused;
    list<list<int>>::iterator it = adjList.begin();
    int currentIndex = 0;
    while(getline(bitacora, currentLine)){
        stringstream currLineStream(currentLine);
        currLineStream >> unused >> unused >> unused >> currentOriginIP >> currentDestinationIP;

        removePort(currentOriginIP);
        removePort(currentDestinationIP);
        
        int originID = IPtoID[currentOriginIP];
        int destID = IPtoID[currentDestinationIP];

        advance(it, originID - currentIndex);
        currentIndex = originID;

        it->push_back(destID);
    }

    map<int, vector<string>> fanOutToIPs;
    it = adjList.begin();
    for(int i = 0; i < n; i++){
        if(fanOutToIPs.find(it->size()) != fanOutToIPs.end()){
            fanOutToIPs[it->size()].push_back(IDtoIP[i]);
        } else {
            fanOutToIPs.insert({it->size(),{IDtoIP[i]}});
        }
        advance(it, 1);
    }

    map<int, vector<string>>::iterator mapIt = fanOutToIPs.end();
    advance(mapIt, -1);

    output << "Posibles IP del Boot Master: " << endl;
    for(string ip : mapIt->second){
        output << ip << endl;
    }
    output << endl;

    mapIt = fanOutToIPs.end();
    for(int i = 0; i < fanOutToIPs.size(); i++){
        advance(mapIt, -1);
        output << "fan-out de " << mapIt->first << ":" << endl;
        for(string ip : mapIt->second){
            output << ip << endl;
        }
        output << endl;
    }

    cout << "He terminado. Mirar archivo output.txt." << endl;

    delete[] IDtoIP;

    return 0;
}