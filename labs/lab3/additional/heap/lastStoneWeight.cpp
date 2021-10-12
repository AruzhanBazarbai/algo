// /*
// 1046. Last Stone Weight
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.
// */
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
    int lastStoneWeight(vector<int>& stones) {
        Maxheap * h=new Maxheap();
        for(int x : stones){
            h->insert(x);
        }
        while(h->a.size()>1){
            int temp1=h->extractMax();
            int temp2=h->extractMax();
            if(temp1!=temp2){
                h->insert(temp1-temp2);
            }
        }
        if(h->a.size()==1) return h->a[0];
        else return 0;
    }
};