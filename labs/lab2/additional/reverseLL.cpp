/*
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode * cur=new ListNode(-5001);
        while(head!=NULL){
            ListNode * temp=new ListNode(head->val);
            if(cur->val==-5001) cur=temp;
            else{
                temp->next=cur;
                cur=temp;
            }
            head=head->next;
        }
        if(cur->val==-5001) return NULL;
        return cur;
    }
};