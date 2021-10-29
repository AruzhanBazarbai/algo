// /*
// Problem C. Vowels and consonants
// Albert does not agree with the basic English alphabet. He thinks, that in the alphabet, first, we need to
// print vowel letters first and then consonants, and both vowels and consonants are ordered alphabetically.
// So he asks us to sort string according to his own alphabet.
// Input
// The first line contains the number n (1 ≤ n ≤ 105
// ), denoting the length of string. The second line contains
// the string s.
// Output
// Print the answer.
// */
#include <iostream>
#include <vector>
using namespace std;
// done

class MinHeap{
    public:
    char a[100010];
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

    void insert(char k){
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
            cout << a[i];
        }
    }
};

int main(){
    int n; string s;
    MinHeap * hv=new MinHeap();
    MinHeap * hc=new MinHeap();
    cin >> n >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='u' || s[i]=='i' || s[i]=='o') hv->insert(s[i]);
        else hc->insert(s[i]);
    }
    string res="";
    while(hv->sz>0){
        res+=hv->extractMin();
    }
    while(hc->sz>0){
        res+=hc->extractMin();
    }
    cout << res;




    return 0;
}