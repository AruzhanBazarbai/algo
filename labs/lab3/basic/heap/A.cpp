/*// Задача №1164. Увеличение приоритета_0
// 
// Запрос задаётся двумя целыми числами i и x. Требуется увеличить значение
// i-го элемента кучи на x и выполнить Sift_Up для восстановления кучи. Гарантируется, что i ∈ [1; N], x ≥ 0, 
// новое значение A[i]+x не превышает 109 и отличается от текущих значений всех остальных элементов кучи.
// Формат входных данных – см. выше.
// Формат выходных данных. В качестве ответа на запрос требуется вывести
// одно число: сообщить, на каком месте массива оказался изменённый элемент
// после выполнения Sift_Up. (Вывести в отдельной строке одно число – соответствующий индекс).
// Кроме того, после выполнения всех запросов требуется вывести кучу в её
// конечном состоянии. 
// */
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
            ind=i;
        }
        return ind;
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
        if(a[right(i)]>a[j] && right(i)<a.size()){
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
    int changeValue(int ind,int x){
        a[ind-1]+=x;
        
        return siftUp(ind-1)+1;
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
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }

    cin >>m;
    while(m--){
        int i;
        cin >> i >> x;
        cout << h->changeValue(i,x) << endl;
    }
        
    h->print();
    return 0;
}