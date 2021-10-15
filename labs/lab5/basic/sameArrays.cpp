/*
Задача №767. Похожие массивы
Назовем два массива похожими, если они состоят из одних и тех же элементов (без учета кратности). 
По двум данным массивам выясните, похожие они или нет.

Входные данные
В первой строке содержится число N  (1 ≤ N ≤ 100000) – размер первого массива. Во второй строке идет N целых чисел, 
не превосходящих по модулю 109 – элементы массива. Далее аналогично задается второй массив.

Выходные данные
Программа должна вывести слово YES, если массивы похожи, и слово NO в противном случае.
*/
#include <iostream>
#include <vector>
using namespace std;
// done

void merge(int l,int r,int mid,int a[]){
    int n1=mid-l+1,n2=r-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[i+l];
    for(int i=0;i<n2;i++) R[i]=a[mid+i+1];
    int uk1=0,uk2=0,k=l;
    while(uk1<n1 && uk2<n2){
        if(L[uk1]<=R[uk2]){
            a[k]=L[uk1];
            uk1++;
        }else{
            a[k]=R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1<n1){
        a[k]=L[uk1];
        uk1++;
        k++;
    }
    while(uk2<n2){
        a[k]=R[uk2];
        uk2++;
        k++;
    }

}

void merge_sort(int l,int r,int a[]){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(l,mid,a);
        merge_sort(mid+1,r,a);
        merge(l,r,mid,a);
    }
}

int main(){
    int k1,k2;
    cin >> k1;
    int a[k1];
    for(int i=0;i<k1;i++) cin >> a[i];
    cin >> k2;
    int b[k2];
    for(int i=0;i<k2;i++) cin >> b[i];
    merge_sort(0,k1-1,a);
    merge_sort(0,k2-1,b);
    vector<int> v1,v2;
    v1.push_back(a[0]);
    v2.push_back(b[0]);
    for(int i=1;i<k1;i++){
        if(a[i]!=a[i-1]) v1.push_back(a[i]);
    }
    for(int i=1;i<k2;i++){
        if(b[i]!=b[i-1]) v2.push_back(b[i]);
    }
    // for(int x: v1) cout << x << " ";
    // cout << endl;
    // for(int x: v2) cout << x << " ";
    bool k=true;
    if(v1.size()!=v2.size()) k=false;
    else{
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                k=false;
                break;
            }
        }
    }

    if(k) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}