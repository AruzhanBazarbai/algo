#include <iostream>
#include <vector>
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
Node *create(int l,int h,vector<int> nums){
    if(l>h) return NULL;
    int mid=(l+h)/2;
    Node * root=new Node(nums[mid]);
    root->left=create(l,mid-1,nums);
    root->right=create(mid+1,h,nums);
    return root;
}
void inOrder(Node * node){
    if(node==NULL){
        cout << "null" << endl;
        return;
    }
    inOrder(node->left);
    cout << node->data << endl;
    inOrder(node->right);

}


int main(){
    vector<int> v={-10,-3,0,5,9};
    // for(auto x : v) cout << x << endl;
    Node * root=create(0,v.size()-1,v);
    inOrder(root);

    
    
    return 0;
}