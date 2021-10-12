/*

*/
#include <iostream>
#include <vector>
using namespace std;
// 
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
    vector<int> v1,v2;
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
    int getHigh(Node * node){
        int h=0,l,r;
        if(node!=NULL){
            l=getHigh(node->left);
            r=getHigh(node->right);
            h=((l>r)? l : r)+1;
        }
        return h;
    }
    // vector<int> isBSTBalanced(Node * node){
    //     int l,r;
    //     if(node!=NULL){
    //         l=getHigh(node->left);
    //         r=getHigh(node->right);
    //         v1.push_back(l);
    //         v2.push_back(r);
    //     }
    //     return v1,v2;
    // }
    // bool isBSTBalanced(Node * node){
    //     int l,r;
    //     if(node!=NULL){
    //         l=getHigh(node->left);
    //         r=getHigh(node->right);
    //         cout << l << " " << r << endl;
    //         if(abs(l-r)>1) return false;
    //     }
    //     return true;
    // }
    // bool isBSTBalanced(Node * node){
    //     return isBSTBalanced(node->left) && isBSTBalanced(node->right);
    // }
};
int main(){
    BST * bst=new BST();
    int x;
    while(cin >> x){
        if(x==0) break;
        bst->root=bst->insert(bst->root,x);
    }
    // bst->isBSTBalanced(bst->root);
    // vector<int> v1,v2=bst->isBSTBalanced(bst->root);
    // int res;
    // for(auto x : v1) cout << x << " ";
    // cout << endl;
    // for(auto x : v2) cout << x << " ";
    // for(int i=0;i<v1.size();i++){
    //     for(int j=0;j<v2.size();j++)
    //     res=abs(v1[i]-v2[j]);
    //     if(res>1){
    //         cout << "NO" << endl;
    //         return 0;
    //     }
    // }
    // cout << "YES" << endl;
    // if(bst->isBSTBalanced(bst->root)) cout << "YES" << endl;
    // else cout << "NO" << endl;
    return 0;


}