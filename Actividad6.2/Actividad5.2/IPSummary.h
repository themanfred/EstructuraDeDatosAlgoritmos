#include <string>
#include <iostream>
#include <vector>

using namespace std;

class IPSummary{
    private:
        int octets[4];
        vector<int> accessorPorts;
        vector<string> accessDates;
        vector<string> failReasons;

    public:
        IPSummary(){
            octets[0] = -1;
            octets[1] = -1;
            octets[2] = -1;
            octets[3] = -1;
        }

        IPSummary(int octet1, int octet2, int octet3, int octet4){
            octets[0] = octet1;
            octets[1] = octet2;
            octets[2] = octet3;
            octets[3] = octet4;
        }

        IPSummary(string stringForm){
            string strRemaining = stringForm;
            for(int i = 0; i < 3; i++){
                int dotIndex = strRemaining.find('.');
                octets[i] = stoi(strRemaining.substr(0, dotIndex));
                strRemaining = strRemaining.substr(dotIndex+1);
            }
            int twoDotIndex = strRemaining.find(':');

            if(twoDotIndex == string::npos){
                octets[3] = stoi(strRemaining.substr(0, strRemaining.size()));
            } else {
                octets[3] = stoi(strRemaining.substr(0, twoDotIndex));
            }
        }

        bool isSameIP(string stringForm){
            string strRemaining = stringForm;
            for(int i = 0; i < 3; i++){
                int dotIndex = strRemaining.find('.');
                if(octets[i] != stoi(strRemaining.substr(0, dotIndex))){
                    return false;
                }
                strRemaining = strRemaining.substr(dotIndex+1);
            }
            int twoDotIndex = strRemaining.find(':');

            if(twoDotIndex == string::npos){
                if(octets[3] != stoi(strRemaining.substr(0, strRemaining.size()))) return false;
            } else {
                if(octets[3] != stoi(strRemaining.substr(0, twoDotIndex))) return false;
            }

            return true;
        }

        void addAccess(int port, string accessDate, string failReason){
            accessorPorts.push_back(port);
            accessDates.push_back(accessDate);
            failReasons.push_back(failReason);
        }

        void addAccess(string ipWithPort, string accessDate, string failReason){
            int twoDotIndex = ipWithPort.find(':');
            int port = stoi(ipWithPort.substr(twoDotIndex+1, 4));
            addAccess(port, accessDate, failReason);
        }

        void print(){
            cout << "Accesos a la IP " << octets[0] << "." << octets[1] << "." << octets[2] << "." << octets[3] << " (" << accessorPorts.size() << " accesos):" << endl;
            for(int i = 0; i < accessorPorts.size(); i++){
                cout << "Puerto: " << accessorPorts[i] << " | Fecha: " << accessDates[i] << " | Razon de falla: " << failReasons[i] << endl; 
            }
            cout << endl;
        }
};