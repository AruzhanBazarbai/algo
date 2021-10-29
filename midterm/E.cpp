
#include <iostream>
using namespace std;
// 
int a[1000010];
int res=1,ind=0;
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
    int getHigh(Node * node){
        int h=0,l,r;
        if(node!=NULL){
            l=getHigh(node->left);
            r=getHigh(node->right);
            h=((l>r)? l : r)+1;
        }
        return h;
    }
    int maxLength(Node * node){
        if(node==NULL) return 0;
        return max(maxLength(node->left),maxLength(node->right))+1;
    }
    int minLength(Node * node){
        if(node==NULL) return 0;
        return min(minLength(node->left),minLength(node->right))+1;
    }
    // считывает количество вершин и проверяет на балансированность
    int calc(Node * node){
        if(node==NULL) return 0;
        int l,r;
        if(node->left!=NULL) l=calc(node->left);
        if(node->right!=NULL) r=calc(node->right);
        a[min(l,r)+1]++;
        return min(l,r);
    }
    // void calc(Node * root){
    //     calc(root);
    // }
    Node * ToBalancedBST(int l,int r){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        Node * root=new Node(a[mid]);
        root->left=ToBalancedBST(l,mid-1);
        root->right=ToBalancedBST(mid+1,r);
        return root;
    }
    bool check(){
        return ok;
    }
    void preOrder(Node * node){
        if(node==NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right); 
    }

  
};
int main(){
    BST * bst=new BST();
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bst->root=bst->insert(bst->root,x);
    }
    bst->calc(bst->root);
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    return 0;

}