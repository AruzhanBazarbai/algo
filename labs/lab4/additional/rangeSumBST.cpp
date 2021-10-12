/*
938. Range Sum of BST
Given the root node of a binary search tree and two integers low and high, return the sum of values of 
all nodes with a value in the inclusive range [low, high].
*/
#include <iostream>
#include <vector>
using namespace std;
class TreeNode{
    public:
    TreeNode * root,*right,*left;
    int val;
    TreeNode(){
        this->root=NULL;
        this->left=NULL;
        this->right=NULL;
        this->val=0;
    }

};
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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root!=NULL && root->val >= low && root->val <= high)
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        if(root!=NULL && root->val < low) return rangeSumBST(root->right,low,high);
        if(root!=NULL && root->val > high) return rangeSumBST(root->left,low,high);
        return 0;
    }
};
int main(){
    Solution * s=new Solution();
    TreeNode * t=new TreeNode();
    s->rangeSumBST(t,0,0);
}