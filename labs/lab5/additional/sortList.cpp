/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
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
#include <vector>
using namespace std;
// done
class ListNode{
    public:
    ListNode * next;
    int val;
    ListNode(){
        this->next=NULL;
        this->val=0;
    }

};
vector<int> a;
int n=0;
void merge(int l,int r,int mid){
    int n1=mid-l+1,n2=r-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[i+l];
    for(int i=0;i<n2;i++) R[i]=a[mid+i+1];
    int uk1=0,uk2=0,k=l;
    while(uk1<n1 && uk2<n2){
        if(L[uk1]<=R[uk2]){
            a[k]=L[uk1];
            uk1++;
        }else{
            a[k]=R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1<n1){
        a[k]=L[uk1];
        uk1++;
        k++;
    }
    while(uk2<n2){
        a[k]=R[uk2];
        uk2++;
        k++;
    }

}

void merge_sort(int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode * temp=head;
        ListNode * cur=head;
        if(!a.empty()) a.clear();
        while(temp!=NULL){
            a.push_back(temp->val);
            temp=temp->next;
        }
        // cout << n << endl;
        merge_sort(0,a.size()-1);
        for(int i=0;i<a.size();i++){
            // cout << a[i] << " ";
            
            if(cur!=NULL) cur->val=a[i];
            // cout << a[i] << endl;
            if(cur!=NULL && cur->next!=NULL) cur=cur->next;
            
        }
        // cout << "-" << a.size();
        // cout << endl;
        return head;
        
    }
};