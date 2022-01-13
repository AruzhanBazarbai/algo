
#include <iostream>
#include <algorithm>
using namespace std;
// 
int a[10000010];
int res=1,ind=0;
class MinHeap{
    public:
    int sz;
    MinHeap(){
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

    int getMin(){
        return a[0];
    }

    void siftUp(int i){
        while(i>0 && a[parent(i)]>a[i]){
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
        if(left(i)>sz-1)
            return;
        int j=left(i);
        if(a[right(i)]<a[j] && right(i)<sz){
            j=right(i);
        }
        if(a[i]>a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int extractMin(){
        int root_value=getMin();
        swap(a[0],a[sz-1]);
        sz--;
        if(sz>0){
            heapify(0);
        }
        return root_value;
    }

    void decreaseKey(int i,int new_value){
        a[i]=new_value;
        siftUp(i);
    }

    void increaseKey(int i,int new_value){
        a[i]=new_value;
        heapify(i);
    }
    void print(){
        for(int i=0;i<sz;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int n,x;
    cin >> n;
    int a[n];
    long long s[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i) s[i]=s[i-1]+a[i];
        else s[i]=a[i];
    }
    int mini=1e7;
    sort(s,s+n);
    for(int i=0;i<n;i++){
        
    }

    // for(int i=0;i<n;i++){
    //     if(mini>abs(a[i])) mini=abs(a[i]);
    //     int sum=a[i]+a[i+1];
    //     if(mini>abs(sum)) mini=abs(sum);
    // }
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=a[j];
    //         if(mini>abs(sum)) mini=abs(sum);
    //     }
    // }
    cout << mini;
    // MinHeap * heap=new MinHeap();
    // for(int i=0;i<n;i++){
    //     cin >> x;
    //     heap->insert(x);
    // }
    // long long sum=0;
    // int mini=1e7;
    // while(n--){
    //     sum+=heap->extractMin();
    //     if(mini>abs(sum)) mini=abs(sum);
    // }
    // cout << mini;



    return 0;
}