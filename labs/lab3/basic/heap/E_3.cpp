#include <iostream>
#include <vector>
using namespace std;
// 
class Maxheap{
    public:
    vector<int > a;
    int sz;
    Maxheap(){
        this->sz=0;
    }

    // int parent(int i){
    //     return (i-1)/2;
    // }

    // int left(int i){
    //     return 2*i+1;
    // }

    // int right(int i){
    //     return 2*i+2;
    // }

    // int getMax(){
    //     return a[0];
    // }

    int siftUp(int i){
        int ind=i;
        while(i>0 && a[(i-1)/2]<a[i]){
            swap(a[(i-1)/2],a[i]);
            i=(i-1)/2;
            ind=i;
        }
        return ind+1;
    }

    void insert(int k){
        sz++;
        a.push_back(k);
        int i=sz-1;
        cout << siftUp(i) << endl;
    }

    int heapify(int i){
        int result;
        if((2*i+1)>(sz-1)){
            return i+1;
        }
        int ind=i;
        int j=2*i+1;
        int x=j;
        if(a[2*i+2]>a[j] && (2*i+2)<sz){
            j=2*i+1;
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            result=heapify(j);
        }else if(x!=j && a[i]<a[x]){
            swap(a[i],a[x]);
            result=heapify(x);
        }
        else{
            return ind+1;
        }
        return result;
        
    }
    void dl(int ind){
        swap(a[ind],a[sz-1]);
        sz--;
        a.pop_back();
        heapify(ind);
        
        
    }

    void extractMax(){
        int root_value=a[0];
        swap(a[0],a[sz-1]);
        a.pop_back();
        sz--;
        if(sz>0){
            cout << heapify(0) << " ";
        }else cout << 0 << " ";
        cout  << root_value << endl;
    }

    void print(){
        for(int i=0;i<sz;i++){
            cout << a[i] << " ";
        }
        // cout << endl;
    }
};


int main(){
    Maxheap * h=new Maxheap();
    size_t n,m,x,t;
    cin >> n >> m;
    while(m--){
        cin >> t;
        if(t==1){
            if(h->sz==0) cout << -1 << endl;
            else h->extractMax();
        }else if(t==2){
            cin >> x;
            if(h->sz==n) cout << -1 << endl;
            else h->insert(x);
        }else if(t==3){
            cin >> x;
            if(x > h->sz) cout << -1 << endl;
            else{
                cout << h->a[x-1] << endl;
                h->dl(x-1);
                
            }
        }
    }
    
        
    h->print();
    return 0;
}