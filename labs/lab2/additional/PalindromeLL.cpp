/**
 * 234. Palindrome Linked List
* Given the head of a singly linked list, return true if it is a palindrome.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
public:
    bool k=true;
    ListNode * f(ListNode* head,ListNode * temp){
        if(temp->next!=NULL) head=f(head,temp->next);
        
        if(head->val!=temp->val){
            k=false;
        }else{
            head=head->next;
        }
        
        return head;
        
    }
    bool isPalindrome(ListNode* head){
        f(head,head);
        return k;
    }
    
};