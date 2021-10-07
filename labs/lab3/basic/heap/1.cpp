// Задача №1164. Увеличение приоритета_0
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
        if(left(i)>a.size()-1)
            return;
        int j=left(i);
        if(a[right(i)]<a[j] && right(i)<a.size()){
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

    void print(){
        for(int i=0;i<a.size();i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Maxheap * h=new Maxheap();
    priority_queue<int> pq;
    int n,m,x;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }

    cin >>m;
    while(m--){
        int i;
        cin >> i >> x;
        a[i-1]+=x;
    }
        
    h->print();
    return 0;
}