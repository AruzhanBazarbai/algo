#include <iostream>
using namespace std;
// done
long long a[10000010];
long long res=0,ind=0,n;
class MinHeap{
    public:
    long long sz;
    MinHeap(){
        this->sz=0;
    }

    long long parent(long long i){
        return (i-1)/2;
    }

    long long left(long long i){
        return 2*i+1;
    }

    long long right(long long i){
        return 2*i+2;
    }

    long long getMin(){
        return a[0];
    }

    void siftUp(long long i){
        while(i>0 && a[parent(i)]>a[i]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }

    void insert(long long k){
        a[sz]=k;
        sz++;
        long long i=sz-1;
        siftUp(i);
    }

    void heapify(long long i){
        if(left(i)>sz-1)
            return;
        long long j=left(i);
        if(a[right(i)]<a[j] && right(i)<sz){
            j=right(i);
        }
        if(a[i]>a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    long long extractMin(){
        long long root_value=getMin();
        swap(a[0],a[sz-1]);
        sz--;
        if(sz>0){
            heapify(0);
        }
        return root_value;
    }


    void print(){
        for(long long i=0;i<sz;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    long long sum(long long s){
        
        while(sz>=2){
            long long x1=extractMin();
            long long x2=extractMin();
            long long temp=x1+x2;
            insert(temp);
            s+=temp;
        }
        return s;
    }
};

int main(){
    MinHeap * h=new MinHeap();
    cin >> n;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        h->insert(x);
    }
    cout << h->sum(0);

    return 0;
}