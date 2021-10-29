/*

Задача №756. Минимум на отрезке
Рассмотрим последовательность целых чисел длины N. По ней с шагом 1 двигается “окно” длины K, 
то есть сначала в “окне” видно первые K чисел, на следующем шаге в “окне” уже будут находиться K чисел, начиная со второго, 
и так далее до конца последовательности. Требуется для каждого положения “окна” определить минимум в нём.

Входные данные
В первой строке входных данных содержатся два числа N и K (1 ≤  N ≤  150000, 1 ≤ K ≤ 10000, K ≤  N) – 
длины последовательности и “окна”, соответственно. На следующей строке находятся N чисел – сама последовательность.

Выходные данные
Выходые данные должны содержать N − K + 1 строк – минимумы для каждого положения “окна”.
*/
#include <iostream>
#include <vector>
using namespace std;
// 
class MinHeap{
    public:
    vector<int > a;

    // int parent(int i){
    //     return (i-1)/2;
    // }

    // int left(int i){
    //     return 2*i+1;
    // }

    // int right(int i){
    //     return 2*i+2;
    // }

    int getMin(){
        return a[0];
    }

    void siftUp(int i){
        while(i>0 && a[(i-1)/2]>a[i]){
            swap(a[(i-1)/2],a[i]);
            i=(i-1)/2;
        }
    }

    void insert(int k){
        a.push_back(k);
        int i=a.size()-1;
        while(i>0 && a[(i-1)/2]>a[i]){
            swap(a[(i-1)/2],a[i]);
            i=(i-1)/2;
        }
    }

    void heapify(int i){
        if(2*i+1>a.size()-1)
            return;
        int j=2*i+1;
        if(a[2*i+2]<a[j] && (2*i+2)<a.size()){
            j=2*i+2;
        }
        if(a[i]>a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int extractMin(){
        int root_value=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
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
        for(int i=0;i<a.size();i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void dl(int x){
        int ind;
        for(int i=0;i<a.size();i++){
            if(a[i]==x){
                ind=i;
                break;
            }
        }
        swap(a[ind],a[a.size()-1]);
        a.pop_back();
        heapify(ind);
        
        
    }
};

int main(){
    int n,x,k,ind=0;
    cin >> n >> k;
    int a[n];
    MinHeap * h=new MinHeap();
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int temp=n-k+1;
    for(int i=0;i<k;i++){
        h->insert(a[i]);
    }
    while(temp--){
        
        // for(auto x:h->a){
        //     cout << x << "----" << ind << endl; 
        // }
        int mini=h->extractMin();
        cout << mini << endl;
        if(a[ind]!=mini){
            h->insert(mini);
            h->dl(a[ind]);
        }
        ind++;
        h->insert(a[ind+k-1]);
        
        
        // h->a.clear();
}
    return 0;
}