// Задача №1171. Пирамидальная сортировка - подробно
/*
Требуется отсортировать по неубыванию с помощью изученного алгоритма
целочисленный массив размера N, выводя также некоторые промежуточные
результаты работы. А именно, должны быть выведены:
• первоначальная куча, построенная вызовом Build_Heap2;
• куча после удаления каждого элемента (то есть после каждой итерации
внешнего цикла);
• отсортированный массив.
См. также пункт «Просеивание и равенство элементов».
Формат входных данных. В первой строке вводится длина массива N. В следующей строке идут элементы массива – N целых чисел, каждое из которых
не превышает по модулю 109
. (1 ≤N≤ 500).
Формат выходных данных. В первой строке должна быть выведена куча, построенная вызовом Build_Heap2, а в каждой из следующих N-1 строк должно
быть выведено состояние кучи после удаления очередного элемента. (Таким
образом, в i-й строке должно быть выведено N+1-i чисел). В последней
(N+1-й) строке нужно вывести отсортированный массив (N чисел). 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
int arr[1000];
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
    void extractMax(int ind){
        int root_value=a[0];
        arr[ind]=root_value;
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
    cout << endl;
    int ind=0;
    while(h->sz > 0){
        h->extractMax(ind);
        ind++;
        h->print();
        if(h->sz!=0) cout << endl;
    }
    for(int i=ind-1;i>=0;i--){
        cout << arr[i] << " ";
    }
    
    return 0;
}