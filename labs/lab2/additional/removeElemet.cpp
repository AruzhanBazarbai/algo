/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * res=new ListNode(0);
        ListNode * temp=res;
        while(head!=NULL){
            if(head->val!=val){
                res->next=head;
                res=res->next;
            }
            head=head->next;
            
        }
        res->next=NULL;
        return temp->next;
    }
};