#include <iostream>
using namespace std;
// done
int maxx;
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
    bool ok;
    BST(){
        this->ok=true;
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
    int getHigh(Node * node){
        if(node==NULL) return 0;
        int l=getHigh(node->left);
        int r=getHigh(node->right);
        maxx=max(maxx,l+r+1);
        return max(l,r)+1;
    }
   
    bool check(){
        return ok;
    }
};
int main(){
    BST *bst=new BST();
    int n,x;
    cin >> n;

    while(n--){
        cin >> x;
        bst->root=bst->insert(bst->root,x);
    }
    bst->getHigh(bst->root);
    cout << maxx;


    return 0;
}