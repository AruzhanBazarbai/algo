/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head=new ListNode(0);
        ListNode * tail=head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1==NULL) tail->next=l2;
        else if(l2==NULL) tail->next=l1;
        return head->next;
    }
            
         
};