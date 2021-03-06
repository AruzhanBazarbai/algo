// // Задача №1172. Просто сортировка
// /*
// 9. Просто сортировка
// Требуется отсортировать по неубыванию с помощью изученного алгоритма
// целочисленный массив размера N.
// Формат входных данных. В первой строке вводится длина массива N. В следующей строке идут элементы массива – N целых чисел, каждое из которых
// не превышает по модулю 109
// . (1 ≤N≤ 105
// ).
// Формат выходных данных. N чисел – элементы исходного массива в порядке
// неубывания. 
// */
#include <iostream>
using namespace std;
// done
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
    MinHeap * heap=new MinHeap();
    for(int i=0;i<n;i++){
        cin >> x;
        heap->insert(x);
    }
    // heap->decreaseKey(4,1);
    // heap->print();

    for(int i=0;i<n;i++){ //heapsort O(n*logn)
        cout << heap->extractMin() << " ";  
    }



    return 0;
}