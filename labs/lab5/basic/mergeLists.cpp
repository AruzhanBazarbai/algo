/*
Задача №1442. Объединение последовательностей
Даны две бесконечных возрастающих последовательности чисел A и B. i-ый член последовательности A равен i2. 
i-ый член последовательности B равен i3.

Требуется найти Cx, где C – возрастающая последовательность, полученная при объединении последовательностей A и B. 
Если существует некоторое число, которое встречается и в последовательности A и в последовательности B, то в последовательность 
C это число попадает в единственном экземпляре.

Входные данные
В единственной строке входного файла дано натуральное число x (1 ≤ x ≤ 107).

Выходные данные
В выходной файл выведите Cx.
*/
#include <iostream>
#include <vector>
using namespace std;
// done
long long a[1000010];
long long n;
void merge(long long l,long long r,long long mid){
    long long n1=mid-l+1,n2=r-mid;
    long long R[n2],L[n1];
    for(int i=0;i<n1;i++) L[i]=a[l+i];

    for(int i=0;i<n2;i++) R[i]=a[mid+i+1];

    long long uk1=0,uk2=0,k=l;
    
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

void merge_sort(long long l,long long r){
    if(l<r){
        long long mid=l+(r-l)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}

int main(){
    cin >> n;
    // for(int i=0;i<n;i++) a[i]=(i+1)*(i+1);
    // for(int i=0;i<n;i++) a[n+i]=(i+1)*(i+1)*(i+1);
    // merge_sort(0,2*n-1);
    // vector<long long> v;
    // v.push_back(a[0]);
    // // for(int i=0;i<2*n;i++) cout << a[i] << endl;
    // for(int i=1;i<2*n;i++){
    //     // cout << a[i] << "----" << endl;
    //     if(a[i]!=a[i-1]){
    //         v.push_back(a[i]);
            
    //     }
    //     if(v.size()==n){
    //         cout << v[n-1];
    //         break;
    //     }
    // }
    // cin >> n;
    long long i=1,j=1,res=0,a=i*i,b=j*j*j;
    while(n--){
        a=i*i;
        b=j*j*j;
        if(a==b){
            n++;
            // res=a;
            i++;
        }else if(a<b){
            res=a;
            i++;
        }else if(a>b){
            res=b;
            j++;
        }
    }
    cout << res << endl;
    return 0;
}