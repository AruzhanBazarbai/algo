//1-нужно проверить является ли дерево bst или нет +
// 2-given the root node of bst and two integers l and h. return the sum of values
//of all nodes with value in inclusive range [l,h]+
// 3- given an integer array nums where the elements are sorted in ascending order, convert
// height balanced bst
// A height balanced bst is a binary tree in which the depth of the two subtrees of every node
// never differs by more than one+
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
	public:
	Node *root;
    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data <= node->data) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }
        return node;        
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

   


};

bool isBSTUtil( Node* node, int min, int max) {
	return (node == NULL) ||
	    (node->data < max && node->data > min) &&
	    isBSTUtil(node->left, min, node->data) &&
	    isBSTUtil(node->right, node->data, max);
}

	

int rangeSumBST(Node* root, int low, int high){
          

    while(root!=NULL){
        if(root->data<low){
            return rangeSumBST(root->right,low,high);
        }
        if(root->data>high){
            return rangeSumBST(root->left,low,high);
        }
        if(root->data>=low && root->data<=high){
            return root->data+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }

    }
    return 0;
}

    Node *create(int l,int h,vector<int> nums)
    {
        if(l>h)
            return NULL;
        int mid=(l+h)/2;
        Node *root=new Node(nums[mid]);
        root->left=create(l,mid-1,nums);
        root->right=create(mid+1,h,nums);
        return root;
    }

int main() {
    BST *bst = new BST();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }

    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

        if(isBSTUtil(root,INT_MIN, INT_MAX)){
            cout << "is BST";
        }else{
            cout << "is not BST";
        }
    //cout << isBSTUtil(bst->root,INT_MIN, INT_MAX) << endl;
    //cout << isBST(root);

    //cout << rangeSumBST(bst->root, 7 ,15);
    std::vector<int> v = {-10,-3,0,5,9};
    //bst->inOrder(create(0, v.size()-1, v));
    return 0;
}