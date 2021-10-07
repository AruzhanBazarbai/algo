/*
Задача №763. Вывод веток
Для полученного дерева выведите список всех вершин, имеющих только одного ребёнка, в порядке возрастания.

Входные данные
Вводится последовательность целых чисел,оканчивающаяся нулем. Построить по ней дерево.

Выходные данные
Выведите список требуемых вершин.
*/
// done
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
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
    void f(Node * node){
        if(node==NULL) return;
        if((node->left!=NULL && node->right==NULL)||(node->left==NULL && node->right!=NULL)){
            v.push_back(node->data);
        }
        
        f(node->left);
        f(node->right); 
    }
   
};
int main(){
    int x;
    BST * bst=new BST();
    while(cin >> x){
        if(x==0) break;
        bst->root=bst->insert(bst->root,x);
    }
    bst->f(bst->root);
    sort(v.begin(),v.end());
    for(auto x : v){
        cout << x << endl;
    }
    return 0;
}