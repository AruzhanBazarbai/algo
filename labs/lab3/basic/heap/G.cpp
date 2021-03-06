// Задача №1170. Построение кучи просеиванием вниз
/*
7. Построение кучи просеиванием вниз (Build_Heap2)
Дан массив. Требуется преобразовать его в кучу с помощью процедуры просеивания вниз. 
Ввод-вывод устроен так же, как в предыдущей задаче. См.
также пункт «Просеивание и равенство элементов». 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Maxheap{
    public:
    vector<int > a;
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

    void siftUp(int i){
        int ind=i;
        while(i>0 && a[(i-1)/2]<a[i]){
            swap(a[(i-1)/2],a[i]);
            i=(i-1)/2;
            ind=i;
        }
        // cout << ind+1 << endl;
    }

    void insert(int k){
        a.push_back(k);
        sz++;
        
        
    }

    void heapify(int i){
        if((2*i+1)>sz-1){
            // cout << i+1 << " ";
            return;
        }
        int ind=i;
        int j=2*i+1;
        if(a[2*i+2]>a[j] && (2*i+2)<sz){
            j=2*i+2;
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
        int root_value=a[0];
        swap(a[0],a[sz-1]);
        a.pop_back();
        sz--;
        if(sz>0){
            heapify(0);
        }
        // else cout << 0 << " ";
        // cout  << root_value << endl;
    }

    void build_heap_down(){
        for(int i=sz/2;i>=0;i--){
            heapify(i);
        }
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
    int n,m,x,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        h->insert(x);
    }
    h->build_heap_down();
    
        
    h->print();
    return 0;
}