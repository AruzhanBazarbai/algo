/*
// Problem F. Balanced Binary Search Tree
// You have an array with 2
// N - 1 elements in it. You want to build the Binary Search Tree on this array,
// adding elements in order of their appearance in array (from left to right). But there is a probability
// of imbalance of such tree. That’s why you decided to shuffle your array to obtain perfectly balanced
// Binary Search Tree after adding elements (from left to right, again). Your task is to print your array after
// appropriate shuffle. If there are several possible shuffles, print the array after applying any of them.
// Note, that you are not asked for building Binary Search Tree, but only for shuffling array.
// Input
// The first line of input consists of single integer N that describes the length of the array (1 6 N 6 15).
// The next line contains 2
// N - 1 integers ai - elements of the array (0 6 ai 6 2 · 109
// ).
// It is guaranteed that there is no duplicates in the array.
// Output
// Print 2
// N - 1 integers - elements in your array after applying required shuffle.
*/
#include <iostream>
using namespace std;
// done
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
    void sort(Node * node){
        if(node==NULL){
            return;
        }
        sort(node->left);
        a[ind]=node->data;
        ind++;
        sort(node->right); 
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
    int calc(Node * node,int cnt){
        if(node==NULL) return 0;
        int l=cnt,r=cnt;
        if(node->left!=NULL) l=calc(node->left,cnt+1);
        if(node->right!=NULL) r=calc(node->right,cnt+1);
        if(abs(l-r)>1) ok=false;
        return max(l,r);
    }
    void calc(Node * root){
        calc(root,1);
    }
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
    while(n--){
        res*=2;
    }
    res--;
    for(int i=0;i<res;i++){
        cin >> x;
        bst->root=bst->insert(bst->root,x);
    }
    bst->sort(bst->root);
    bst->root=bst->ToBalancedBST(0,res-1);
    bst->preOrder(bst->root);
    cout << endl;
    bst->inOrder(bst->root);
    return 0;

}


