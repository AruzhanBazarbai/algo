/*
108. Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    Node *right,*left;
    int val;
    Node(int val){
        this->left=NULL;
        this->right=NULL;
        this->val=val;
    }

};

Node * sortedArrayToBST(vector<int>& nums) {
    return insert(nums,0,nums.size()-1);
}
Node * insert(vector<int>& nums,int l,int r){
    if(l>r) return NULL;
    int mid=l+(r-l)/2;
    Node * root=new Node(nums[mid]);
    root->left=insert(nums,l,mid-1);
    root->right=insert(nums,mid+1,r);
    return root;
}

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9};
    Node * bst=sortedArrayToBST(v);
}