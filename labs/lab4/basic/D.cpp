// Задача №760. Обход
// Выведите все элементы полученного дерева в порядке возрастания.

// Входные данные
// Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит. По данной последовательности требуется построить дерево.

// Выходные данные
// Выведите ответ на задачу.
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
        cout << node->data << endl;
        inOrder(node->right); 
    }
    Node * findMax(Node * node){
        Node * tmp;
        while(node->right!=NULL){
            tmp=node;
            node=node->right;

        }
        return tmp;
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

    
};
int main(){
    int x;
    BST * bst=new BST();
    while(cin >> x){
        if(x==0) break;
        bst->root=bst->insert(bst->root,x);
        
    }
    bst->inOrder(bst->root);

    
    
    return 0;


}