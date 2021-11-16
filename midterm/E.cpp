#include <iostream>
using namespace std;
// 
int a[1000010];
int cnt[1000010];
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
    void calc(Node* node) {
    if (node == nullptr) return;
    int cur = 2;
    Node* l = node;
    Node* r = node;
    while (l->left != nullptr and r->right != nullptr) {
        cnt[cur]++;
        cur++;
        l = l->left;
        r = r->right;
    }
    calc(node->left);
    calc(node->right);
    }
    void calc() {
        calc(root);
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
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bst->root=bst->insert(bst->root,x);
    }
    
    bst->calc();
    for(int i=2;i<=n;i++){
        cout << cnt[i] << " ";
    }
    return 0;

}