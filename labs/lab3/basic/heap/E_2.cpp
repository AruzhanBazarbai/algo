// /*
// Задача №1168. Приоритетная очередь с удалением
// Условие этой задачи отличается от условия предыдущей лишь наличием ещё
// одного типа запроса – запроса на удаление заданного (не обязательно максимального) элемента. Это будет запрос типа 3 с единственным параметром,
// задающим индекс элемента, который требуется удалить из кучи.
// В ответ на запрос типа 3 следует вывести:
// • -1, если элемента с таким индексом нет и удаление невозможно. (При
// этом куча не должна измениться).
// • Иначе – значение удаленного элемента.
// Гарантируется, что параметр является неотрицательным целым не больше
// 109
// . 
// */
#include <iostream>
#include <vector>
using namespace std;
// 
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
        // int par=(i-1)/2;
        while(i>0 && a[(i-1)/2]<a[i]){
            swap(a[(i-1)/2],a[i]);
            i=(i-1)/2;
            ind=i;
        }
        // cout << ind+1 << endl;
        return ind+1;
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        cout << siftUp(i) << endl;
    }

    int heapify(int i){
        if((2*i+1)>a.size()-1){
            // cout << i+1 << " ";
            return i+1;
        }
        int ind=i;
        int j=2*i+1;
        if(a[2*i+2]>a[j] && (2*i+2)<a.size()){
            j=2*i+1;
        }
        if(a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }else{
            // cout << ind+1 << " ";
            return ind+1;
        }
        
    }
    void dl(int ind){
        // if(a.size()==1) a.pop_back();
        // else if(a.size()==2){
        //     if(ind==0){
        //         swap(a[0],a[1]);
        //         a.pop_back();
        //     }else a.pop_back();
        // }else if(a.size()>2){
        //     if(ind==0){
        //         swap(a[0],a[a.size()-1]);
        //         a.pop_back();
        //         heapify(0);
        //     }else{
        //         swap(a[ind],a[a.size()-1]);
        //         a.pop_back();
        //         if(left(ind)<a.size() && a[ind]<a[left(ind)]){
        //             heapify(ind);
        //         }else if(parent(ind)>0 && a[ind]>a[parent(ind)]){
        //             siftUp(ind);
        //         }
        //     }
        // }
        swap(a[ind],a[a.size()-1]);
        a.pop_back();
        heapify(ind);
    }

    void extractMax(){
        int root_value=getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            cout << heapify(0) << " ";
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
    size_t n,m,x,t;
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
        }else if(t==3){
            cin >> x;
            if(x > h->a.size()) cout << -1 << endl;
            else{
                cout << h->a[x-1] << endl;
                h->dl(x-1);
                
            }
            // else
        }
    }
    
        
    h->print();
    return 0;
}