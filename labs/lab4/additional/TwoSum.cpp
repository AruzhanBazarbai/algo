/*653. Two Sum IV - Input is a BST

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is 
equal to the given target.
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
    vector<int> v;
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int l=0,r=v.size()-1;
        for(auto x:v) cout << x << endl;
        while(l<r){
            if(v[l]+v[r]==k){
                return true;
            }else if(v[l]+v[r]<k){
                l++;
            }else if(v[l]+v[r]>k){
                r--;
            }
        }
        return false;
    }
    void inOrder(TreeNode * root){
        if(root==NULL) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
   
};