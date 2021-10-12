/*
1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Maxheap{
    public:
    vector<int > a;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    int getMax(){
        return a[0];
    }

    void siftUp(int i){
        int ind=i;
        while(i>0 && a[parent(i)]<a[i]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i)>a.size()-1){
            return;
        }
        int j=left(i);
        if(a[right(i)]>a[j] && right(i)<a.size()){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }   
    }
    int extractMax(){
        int root_value=getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }
        return root_value;
    }

};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        Maxheap * h=new Maxheap();
        for(int i=0;i<nums.size();i++){
            h->insert(nums[i]);
        }
        int ind=2,res=1;
        while(ind--){
            res*=(h->extractMax()-1);
        }
        return res;
    }
};