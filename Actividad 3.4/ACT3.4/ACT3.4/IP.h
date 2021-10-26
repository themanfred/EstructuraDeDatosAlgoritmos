#include <string>

using namespace std;

class IP{
    private:
        int octets[4];
        int port;
        string asString;
    public:
        IP(){
            octets[0] = -1;
            octets[1] = -1;
            octets[2] = -1;
            octets[3] = -1;
            port = -1;
            asString = "-1.-1.-1.-1:-1";
        }
        IP(int octet1, int octet2, int octet3, int octet4, int port){
            octets[0] = octet1;
            octets[1] = octet2;
            octets[2] = octet3;
            octets[3] = octet4;
            this->port = port;
            asString = to_string(octets[0]) + "." + to_string(octets[1]) + 
                "." + to_string(octets[2]) + "." + to_string(octets[3]) 
                + ":" + to_string(port);
        }
        IP(string stringForm){
            asString = stringForm;
            string strRemaining = stringForm;
            for(int i = 0; i < 3; i++){
                int dotIndex = strRemaining.find('.');
                octets[i] = stoi(strRemaining.substr(0, dotIndex));
                strRemaining = strRemaining.substr(dotIndex+1);
            }
            int twoDotIndex = strRemaining.find(':');
            octets[3] = stoi(strRemaining.substr(0, twoDotIndex));
            port = stoi(strRemaining.substr(twoDotIndex+1));
        }

        string getAsString(){
            return asString;
        }

        string getAsStringNoPort(){
            int twoDotIndex = asString.find(':');
            return asString.substr(0, twoDotIndex);
        }

        //Sobreescribimos los operadores para poder comparar entre IPs
        bool operator==(const IP &otherIP){
            return octets[0] == otherIP.octets[0] && 
                   octets[1] == otherIP.octets[1] &&  
                   octets[2] == otherIP.octets[2] && 
                   octets[3] == otherIP.octets[3];
        }

        bool operator!=(const IP &otherIP){
            return octets[0] != otherIP.octets[0] || 
                   octets[1] != otherIP.octets[1] ||  
                   octets[2] != otherIP.octets[2] || 
                   octets[3] != otherIP.octets[3];
        }

        bool operator<(const IP &otherIP){
            if(octets[0] != otherIP.octets[0]){
                return octets[0] < otherIP.octets[0];
            } else {
                if(octets[1] != otherIP.octets[1]){
                    return octets[1] < otherIP.octets[1];
                } else {
                    if(octets[2] != otherIP.octets[2]){
                        return octets[2] < otherIP.octets[2];
                    } else {
                        if(octets[3] != otherIP.octets[3]){
                            return octets[3] < otherIP.octets[3];
                        } else {
                            return port < otherIP.port;
                        }
                    }
                }
            }
        }

        bool operator<=(const IP &otherIP){

            if(*this == otherIP)
                return true;

            if(octets[0] != otherIP.octets[0]){
                return octets[0] < otherIP.octets[0];
            } else {
                if(octets[1] != otherIP.octets[1]){
                    return octets[1] < otherIP.octets[1];
                } else {
                    if(octets[2] != otherIP.octets[2]){
                        return octets[2] < otherIP.octets[2];
                    } else {
                        if(octets[3] != otherIP.octets[3]){
                            return octets[3] < otherIP.octets[3];
                        } else {
                            return port < otherIP.port;
                        }
                    }
                }
            }
        }

        bool operator>(const IP &otherIP){
            if(octets[0] != otherIP.octets[0]){
                return octets[0] > otherIP.octets[0];
            } else {
                if(octets[1] != otherIP.octets[1]){
                    return octets[1] > otherIP.octets[1];
                } else {
                    if(octets[2] != otherIP.octets[2]){
                        return octets[2] > otherIP.octets[2];
                    } else {
                        if(octets[3] != otherIP.octets[3]){
                            return octets[3] > otherIP.octets[3];
                        } else {
                            return port > otherIP.port;
                        }
                    }
                }
            }
        }

        bool operator>=(const IP &otherIP){

            if(*this == otherIP)
                return true;
            
            if(octets[0] != otherIP.octets[0]){
                return octets[0] > otherIP.octets[0];
            } else {
                if(octets[1] != otherIP.octets[1]){
                    return octets[1] > otherIP.octets[1];
                } else {
                    if(octets[2] != otherIP.octets[2]){
                        return octets[2] > otherIP.octets[2];
                    } else {
                        if(octets[3] != otherIP.octets[3]){
                            return octets[3] > otherIP.octets[3];
                        } else {
                            return port > otherIP.port;
                        }
                    }
                }
            }
        }



};