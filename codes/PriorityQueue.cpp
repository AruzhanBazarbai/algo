// /*
// Задача №1167. Приоритетная очередь
// Формат входных данных
// В первой строке вводятся два числа – максимальный размер приоритетной
// очереди N и количество запросов M. (1 ≤ M, N ≤ 105
// ).
// Далее идут M строк, в каждой строке – по одному запросу.
// Первое число в запросе задаёт его тип, остальные числа (если есть) – параметры запроса.
// Тип 1 – извлечь максимальный (без параметров), 
//  12
// Тип 2 – добавить данный элемент в очередь. Запрос имеет один параметр –
// число из диапазона [-109
// ; 109
// ]
// Формат выходных данных
// В ответ на запрос типа 1 следует вывести:
// • Если извлекать было нечего (очередь пуста), то -1.
// • Иначе, как и в предыдущей задаче – два числа: первое – индекс конечного положения элемента после его просеивания (если же удалён был
// последний элемент и просеивать осталось нечего, вывести 0); второе –
// значение извлечённого элемента.
// В ответ на запрос типа 2 следует вывести:
// • Если добавить нельзя (нет места, поскольку в очереди уже N элементов), то вывести -1. (При этом куча не должна измениться).
// • Иначе – индекс добавленного элемента.
// Кроме того, после выполнения всех запросов требуется вывести кучу в её
// конечном состоянии
//  */
#include <iostream>
#include <vector>
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

    void siftUp(int i){
        int ind=i;
        while(i>0 && a[parent(i)]<a[i]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
            ind=i;
        }
        cout << ind+1 << endl;
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i)>a.size()-1){
            cout << i+1 << " ";
            return;
        }
        int ind=i;
        int j=left(i);
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
    void extractMax(){
        int root_value=getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }else cout << 0 << " ";
        cout  << root_value << endl;
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
    int n,m,x,t;
    cin >> n >> m;
    while(m--){
        cin >> t;
        if(t==1){
            if(h->a.empty()) cout << -1 << endl;
            else h->extractMax();
        }else if(t==2){
            cin >> x;
            if(h->a.size()==n) cout << -1 << endl;
            else h->insert(x);
        }
    }
    
        
    h->print();
    return 0;
}