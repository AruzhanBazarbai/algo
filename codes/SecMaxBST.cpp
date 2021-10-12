/*
Задача №759. Второй максимум
Выведите второй по величине элемент в построенном дереве. Гарантируется, что такой найдется.

Входные данные
Дана последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит.

Выходные данные
Выведите ответ на задачу.
*/
#include <iostream>
using namespace std;
// done
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
        root=NULL;
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
    Node * findSecondMax(Node * node){
        Node * max1=findMax(node);
        node=deleteData(node,max1->data);
        Node * max2=findMax(node);
        cout << max2->data << endl;
        return node;

    }

    int getHigh(Node * node){
        int h=0,l,r;
        if(node!=NULL){
            l=getHigh(node->left);
            r=getHigh(node->right);
            h=((l>r)? l : r)+1;
        }
        return h;
    }
};
int main(){
    BST * bst=new BST();
    int x;
    while(cin >> x){
        if(x==0) break;
        bst->root=bst->insert(bst->root,x);
    }
    bst->root=bst->findSecondMax(bst->root);

    
    
    
    return 0;


}