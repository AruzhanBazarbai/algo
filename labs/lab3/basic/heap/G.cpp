#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 
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
            ind=i;
        }
        // cout << ind+1 << endl;
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        swap(a[0],a[i]);
        siftUp(i);
        heapify(0);
        
        
    }

    void heapify(int i){
        if(left(i)>a.size()-1){
            // cout << i+1 << " ";
            return;
        }
        int ind=i;
        int j=left(i);
        if(a[right(i)]>a[j] && right(i)<a.size()){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
        // else{
        //     cout << ind+1 << " ";
        //     return;
        // }
        
    }
    void extractMax(){
        int root_value=getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }
        // else cout << 0 << " ";
        // cout  << root_value << endl;
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
    int n,m,x,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }
    
        
    h->print();
    return 0;
}