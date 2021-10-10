// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp=head;
        while(temp && temp->next){
            if(temp->val==temp->next->val) temp->next=temp->next->next;
            else temp=temp->next;
                    
            
        }
        
        return head;
    }
};
 