#include <iostream>
using namespace std;
// 
int a[1000010];
int n;
void merge(int l,int r,int mid){
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

void merge_sort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}

int main(){
   int n,x,k,ind=0,mini=1e9,ind2=0;
    cin >> n >> k;
    int a[n];
    int b[k];
    ind=k-1;
    // MinHeap * h=new MinHeap();
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i<k){
            b[i]=a[i];
            if(mini>a[i]) mini=a[i];
        }
    }
    int temp=n-k+1;
    while(temp--){
        if(ind==k-1) cout << mini << endl;
        else{
            b[0]=a[ind];
            mini=1e9;
            for(int i=0;i<k;i++){
                if(mini>b[i]) mini=b[i];
            }
            cout << mini << endl;
        }
        ind++;
        // for(int i=ind;i<ind+k;i++){
        //     h->insert(a[i]);
        // }
        // cout << h->extractMin() << endl;
        // h->a.clear();
        
    }

    return 0;
}