#include "IP.h"
#include <vector>

class Node{
    private:
        int accessNum;
        vector<IP> ips;
        Node *left;
        Node *right;
    public:
        Node(int accessNum){
            this->accessNum = accessNum;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(int accessNum, vector<IP> ips){
            this->accessNum = accessNum;
            this->ips = ips;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(int accessNum, vector<IP> ips, Node *left, Node *right){
            this->accessNum = accessNum;
            this->ips = ips;
            this->left = left;
            this->right = right;
        }
        void addIP(IP ip){
            ips.push_back(ip);
        }
        int getAccessNum(){
            return this->accessNum;
        }
        Node* getRight(){
            return this->right;
        }
        Node* getLeft(){
            return this->left;
        }
        vector<IP> getIPs(){
            return this->ips;
        }
        void setData(int accessNum){
            this->accessNum = accessNum;
        }
        void setRight(Node *right){
            this->right = right;
        }
        void setLeft(Node *left){
            this->left = left;
        }
};