/*
237. Delete Node in a Linked List
Write a function to delete a node in a singly-linked list. 
You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode * next;
    ListNode(int data){
        this->val=data;
        this->next=NULL;
    }
};
ListNode * l1=new ListNode(0);
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;
    }
};