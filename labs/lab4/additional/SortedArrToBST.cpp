/*
108. Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
class TreeNode{
    public:
    TreeNode * root,*right,*left;
    int val;
    TreeNode(int val){
        this->root=NULL;
        this->left=NULL;
        this->right=NULL;
        this->val=val;
    }

};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums,0,nums.size()-1);
    }
    TreeNode * insert(vector<int>& nums,int l,int r){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode * root=new TreeNode(nums[mid]);
        root->left=insert(nums,l,mid-1);
        root->right=insert(nums,mid+1,r);
        return root;
    }
};