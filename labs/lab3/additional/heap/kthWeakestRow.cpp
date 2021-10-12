/*
1337. The K Weakest Rows in a Matrix
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
#include <iostream>
#include <vector>
using namespace std;
// done
class MinHeap{
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

    auto getMin(){
        return a[0];
    }

    void siftUp(int i){
        while(i>0 && a[parent(i)].second>=a[i].second){
            if(a[parent(i)].second==a[i].second && a[parent(i)].first>a[i].first){
                swap(a[parent(i)],a[i]);
            }else if(a[parent(i)].second>a[i].second){
                swap(a[parent(i)],a[i]);
                
            }
            i=parent(i);
        }
    }

    void insert(int ind,int k){
        a.push_back(make_pair(ind,k));
        int i=a.size()-1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i)>a.size()-1)
            return;
        int j=left(i);
        if((a[right(i)].second<a[j].second && right(i)<a.size())||(a[right(i)].second==a[j].second && a[right(i)].first<a[j].first && right(i)<a.size())){
            j=right(i);
        }
        if(a[i].second>a[j].second){
            swap(a[i],a[j]);
            heapify(j);
        }else if(a[i].second==a[j].second && a[i].first>a[j].first){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    auto extractMin(){
        auto root_value=getMin();
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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        MinHeap * h=new MinHeap();
        vector<int> v;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) cnt++;
            }
            h->insert(i,cnt);
        }
        while(k--){
            v.push_back(h->extractMin().first);
        }
        return v;
    }
};