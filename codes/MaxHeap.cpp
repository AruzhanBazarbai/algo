
#include <iostream>
using namespace std;
int a[10000010];
int res=1,ind=0;
class Maxheap{
    public:
    int sz;
    Maxheap(){
        this->sz=0;
    }
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

    int siftUp(int i){
        int ind=i;
        while(i>0 && a[parent(i)]<a[i]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }

    void insert(int k){
        a[sz]=k;
        sz++;
        int i=sz-1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i)>sz-1){
            return;
        }
        int j=left(i);
        if(a[right(i)]>a[j] && right(i)<sz){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }   
    }
    int extractMax(){
        int root_value=getMax();
        swap(a[0],a[sz-1]);
        sz--;
        if(sz>0){
            heapify(0);
        }
        return root_value;
    }

    void print(){
        for(int i=0;i<sz;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Maxheap * h=new Maxheap();
    // priority_queue<int> pq;
    int n,m,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }
        
    h->print();
    return 0;
}