#include <iostream>
#include "Node.h"
#include <queue>

using namespace std;

class BST{
    private:
        Node* root;
    public:
        BST(){
            root = nullptr;
        }
        ~BST(){
            destroy(root);
        }

        void addIPToAccessNum(IP ip, int accessNum){
            Node *current = root;
            Node *father = nullptr;

            while(current != nullptr){
                if(accessNum == current->getAccessNum()){
                    current->addIP(ip);
                    return;
                }

                father = current;
                current = (accessNum > current->getAccessNum()) ? current->getRight() : current->getLeft();
            }

            if(father == nullptr){
                root = new Node(accessNum, {ip});
            } else {
                (father->getAccessNum() > accessNum)? father->setLeft(new Node(accessNum, {ip})) : father->setRight(new Node(accessNum, {ip}));
            }
        }

        void destroy(Node *node){
            if(node != nullptr){
                destroy(node->getLeft());
                destroy(node->getRight());
                delete root;
            }
        }

        bool search(int data){
            Node *current = root;
            while(current != nullptr){
                if(data == current->getAccessNum())
                    return true;
                current = (data > current->getAccessNum()) ? current->getRight() : current->getLeft();
            }
            return false;
        }

        void insert(int data){
            Node *current = root;
            Node *father = nullptr;

            while(current != nullptr){
                if(current->getAccessNum() == data)
                    return;

                father = current;
                current = (data > current->getAccessNum()) ? current->getRight() : current->getLeft();
            }

            if(father == nullptr){
                root = new Node(data);
            } else {
                (father->getAccessNum() > data)? father->setLeft(new Node(data)) : father->setRight(new Node(data));
            }
        }
        
        void visit(int visitType){
            switch(visitType){
                case 1:
                    cout << "BST en preorden: " << endl;
                    cout << "-------------------------------" << endl;
                    visitByPreorder(root);
                    cout << endl;
                    break;
                case 2:
                    cout << "BST en inorden: " << endl;
                    cout << "-------------------------------" << endl;
                    visitByInorder(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "BST en postorden: " << endl;
                    cout << "-------------------------------" << endl;
                    visitByPostorder(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "BST nivel por nivel: " << endl;
                    cout << "-------------------------------" << endl;
                    visitLevelByLevel();
                    cout << endl;
                    break;
                case 5:
                    cout << "BST en inorden inverso: " << endl;
                    cout << "-------------------------------" << endl;
                    visitByInverseInorder(root);
                    break;
            }
        }

        void visitByPreorder(Node* node){
            if(node == nullptr)
                return;
            
            cout << node->getAccessNum() << " accesos: " << endl;
            for(IP ip : node->getIPs()){
                cout << ip.getAsStringNoPort() << endl;
            }
            cout << "-------------------------------" << endl;

            visitByPreorder(node->getLeft());
            visitByPreorder(node->getRight());
        }

        void visitByInorder(Node* node){
            if(node == nullptr)
                return;
            
            visitByInorder(node->getLeft());

            cout << node->getAccessNum() << " accesos: " << endl;
            for(IP ip : node->getIPs()){
                cout << ip.getAsStringNoPort() << endl;
            }
            cout << "-------------------------------" << endl;

            visitByInorder(node->getRight());
        }

        void visitByInverseInorder(Node* node){
            if(node == nullptr)
                return;
            
            visitByInverseInorder(node->getRight());

            cout << node->getAccessNum() << " accesos: " << endl;
            for(IP ip : node->getIPs()){
                cout << ip.getAsStringNoPort() << endl;
            }
            cout << "-------------------------------" << endl;

            visitByInverseInorder(node->getLeft());
        }

        void visitByPostorder(Node* node){
            if(node == nullptr)
                return;
            
            visitByPostorder(node->getLeft());
            visitByPostorder(node->getRight());

            cout << node->getAccessNum() << " accesos: " << endl;
            for(IP ip : node->getIPs()){
                cout << ip.getAsStringNoPort() << endl;
            }
            cout << "-------------------------------" << endl;
        }

        void visitLevelByLevel(){
            if(root == nullptr)
                return;
            
            queue<Node*> nodeQueue;
            nodeQueue.push(root);

            while(!nodeQueue.empty()){
                Node* node = nodeQueue.front();

                cout << node->getAccessNum() << " accesos: " << endl;
                for(IP ip : node->getIPs()){
                    cout << ip.getAsStringNoPort() << endl;
                }
                cout << "-------------------------------" << endl;

                nodeQueue.pop();

                if(node->getLeft() != nullptr)
                    nodeQueue.push(node->getLeft());
                if(node->getRight() != nullptr)
                    nodeQueue.push(node->getRight());
            }
        }

        void printXIPsWithMoreAccesses(int x){
            printXIPsWithMoreAccesses(x, root);
        }

        void printXIPsWithMoreAccesses(int &x, Node* node){
            if(node == nullptr)
                return;

            printXIPsWithMoreAccesses(x, node->getRight());

            for(IP ip : node->getIPs()){
                if(x <= 0) return;
                cout << ip.getAsStringNoPort() << "-> " << node->getAccessNum() << " accesos" << endl;
                x--;
            }

            printXIPsWithMoreAccesses(x, node->getLeft());
        }

        int height(Node* node, int currentHeight){
            if(node == nullptr)
                return currentHeight;

                return max(height(node->getLeft(), currentHeight+1), height(node->getRight(), currentHeight+1));
        }

        int height(){
            return height(root, -1);
        }

        void ancestors(int data){
            cout << "Ancestros (del mas viejo al mas joven): " << endl;
            Node *current = root;
            while(current != nullptr){
                if(data == current->getAccessNum()){
                    cout << endl;
                    return;
                }
                cout << current->getAccessNum() << " ";
                current = (data > current->getAccessNum()) ? current->getRight() : current->getLeft();
            }
        }

        int whatlevelamI(int data){
            Node *current = root;
            int contadorNivel = 0;
            while(current != nullptr){
                if(data == current->getAccessNum())
                    return contadorNivel;
                current = (data > current->getAccessNum()) ? current->getRight() : current->getLeft();
                contadorNivel++;
            }
            return -1;
        }
        
};