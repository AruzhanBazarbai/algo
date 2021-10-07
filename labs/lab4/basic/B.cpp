/*
Задача №758. Количество элементов
Подсчитайте количество элементов в получившемся дереве и выведите это 
количество.

Входные данные
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит.

Выходные данные
Выведите ответ на задачу.
элементы должны быть уникальными
*/
// done
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST{
    public:
    Node * root;
    int size;
    BST(){
        this->root=NULL;
        this->size=0;
    }
    Node * insert(Node * node,int data){
        if(node==NULL){
            node=new Node(data);
            size++;
            return node;
        }
        if(data<node->data){
            node->left=insert(node->left,data);
        }else if(data>node->data){
            node->right=insert(node->right,data);
        }
        return node;
    }
    void inOrder(Node * node){
        if(node==NULL){
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right); 
    }
    Node * findMax(Node * node){
        while(node->right!=NULL){
            node=node->right;
        }
        return node;
    }
    Node * findMin(Node * node){
        while(node->left!=NULL){
            node=node->left;
        }
        return node;
    }
    Node * deleteData(Node * node,int data){
        if(node==NULL) return NULL;
        else if(data<node->data){
            node->left=deleteData(node->left,data);
        }else if(data>node->data){
            node->right=deleteData(node->right,data);
        }else{
            if(node->left==NULL && node->right==NULL){
                return NULL;
            }else if(node->left==NULL && node->right!=NULL){
                node=node->right;
            }else if(node->left!=NULL && node->right==NULL){
                node=node->left;
            }else{
                Node * tmp=findMax(node->left);
                node->data=tmp->data;
                node->left=deleteData(node->left,tmp->data);
            }
        }
        return node;

    }
    int getHigh(Node * node){
        int h1=0,h2=0;
        while(node!=NULL){
            node=node->left;
            h1++;
        }
        return h1;



    }
};
int main(){
    int x;
    BST * bst=new BST();
    while(cin >> x){
        if(x==0) break;
        bst->root=bst->insert(bst->root,x);
        
        
    }
    cout << bst->size;

    
    
    return 0;


}