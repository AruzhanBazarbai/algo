#include <iostream>
using namespace std;
int a[1000010];
int n;
void quickSort(int l,int r){
    int mid=(l+r)/2;
    int i=l,j=r,p=a[mid];
    while(i<j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
        if(l<j) quickSort(l,j);
        if(r>i) quickSort(i,r);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    quickSort(0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << " ";

    return 0;
}