#include <iostream>
using namespace std;
int a[1000010];
int n;

void merge(int l,int r,int mid){
    int n1=mid-l+1,n2=r-mid;
    int R[n2],L[n1];
    for(int i=0;i<n1;i++) L[i]=a[l+i];

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

void merge_sort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    merge_sort(0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << " ";

    return 0;
}