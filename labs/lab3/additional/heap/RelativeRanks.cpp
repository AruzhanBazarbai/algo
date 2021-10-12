/*
506. Relative Ranks
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Maxheap{
    public:
    vector<pair<int,int> > a;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    auto getMax(){
        return a[0];
    }

    void siftUp(int i){
        int ind=i;
        while(i>0 && a[parent(i)].second<a[i].second){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }

    void insert(int ind,int x){
        a.push_back(make_pair(ind,x));
        int i=a.size()-1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i)>a.size()-1){
            return;
        }
        int j=left(i);
        if(a[right(i)].second>a[j].second && right(i)<a.size()){
            j=right(i);
        }
        if(a[i].second<a[j].second){
            swap(a[i],a[j]);
            heapify(j);
        }   
    }
    auto extractMax(){
        auto root_value=getMax();
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
    vector<string> findRelativeRanks(vector<int>& score) {
        Maxheap * h=new Maxheap();
        
        for(int i=0;i<score.size();i++){
           h->insert(i,score[i]);
        } 
        vector<string> v(score.size());
        size_t n=score.size();
        int ind=1;
        while(!h->a.empty()){
            auto x=h->extractMax();
            if(ind==1) v[x.first]="Gold Medal";
            else if(ind==2) v[x.first]="Silver Medal";
            else if(ind==3) v[x.first]="Bronze Medal";
            else if(ind==1) v[x.first]="Gold Medal";
            else v[x.first]=to_string(ind);
            ind++;
        }
        return v;
        
    }
};