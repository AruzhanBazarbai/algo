// /*
// Problem A. Standard problem about soccer
// Kakyoin loves football and he goes to the final of World Cup. At the stadium, he noticed that there are
// n rows, each of which places a distinct number of people. The price of the ticket depends on the row.
// If there are k (k > 0) free seats in the row, then the price of one ticket will be equal to k. What is the
// maximum amount of money stadium management can get if there are x people in line?
// Input
// The first line consists of n and x (1 ≤ n, x ≤ 105
// ). n denotes the number of seating rows in the stadium
// and x denotes the number of football fans waiting in the line to get a ticket for the match. Next line
// consists of n space separated integers a1, a2, a3, .... an where ai (1 ≤ ai ≤ 105
// ) denotes the number of
// empty seats initially in the i-th row.
// It is guaranteed that there are enough free seats for all visitors.
// Output
// Print the answer.
// */
#include <iostream>
// #include <bits/stdc++.h>
// done
using namespace std;
int a[100010];
int n;
class Maxheap{
    public:
    // vector<int > a;
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
        int ind=j;
        if(a[right(i)]>a[j] && right(i)<sz){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int extractMax(){
        int root_value=a[0];
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
    int x,k;
    cin >> n >> x;
    // int a[n];
    for(int i=0;i<n;i++){
        cin >> k;
        h->insert(k);
    }
    long long cnt=0;
    while(x--){
        cnt+=a[0];
        a[0]--;
        h->heapify(0);
    }
    cout << cnt;

    return 0;
}