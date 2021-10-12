/*
// Задача №1166. Извлечение максимального
Дана куча размера N> 1. Требуется N-1 раз выполнить извлечение максимального элемента. Как рассказано выше, в процессе выполнения процедуры
Extract_Max последний элемент кучи помещается в её корень, а затем просеивается вниз вызовом Sift_Down. После каждого выполнения процедуры
Extract_Max нужно будет вывести индекс конечного положения этого элемента после просеивания, а также значение извлечённого максимального
элемента.
Формат входных данных
В первой строке задан размер кучи N ∈[2; 105
]. Во второй строке вводится
сама куча – N различных целых чисел, каждое из диапазона [-109
; 109
]. (Гарантируется, что эти числа составляют корректную максимальную кучу).
Формат выходных данных
Требуется вывести N-1 строку, в каждой – два числа. Первое – индекс конечного положения элемента после его просеивания; 
второе – значение извлечённого элемента.
*/
#include <iostream>
#include <bits/stdc++.h>
// done
using namespace std;

class Maxheap{
    public:
    vector<int > a;

    int parent(int i){
        return (i-1)/2;
    }

    size_t left(int i){
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
            ind=i;
        }
        return ind;
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        siftUp(i);
    }

    void heapify(size_t i){
        if(left(i)>a.size()-1){
            cout << i+1 << " ";
            return;
        }
        size_t ind=i;
        size_t j=left(i);
        if(a[right(i)]>a[j] && right(i)<a.size()){
            j=right(i);
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }else{
            cout << ind+1 << " ";
            return;
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
    // priority_queue<int> pq;
    int n,m,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }
    while(h->a.size()!=1){
        cout << h->extractMax() << endl;
    }

    // cin >>m;
    // while(m--){
    //     int i;
    //     cin >> i >> x;
    //     // cout << h->changeValue(i,x) << endl;
    //     h->a[i-1]-=x;
    //     h->heapify(i-1);
    // }
        
    // h->print();
    return 0;
}