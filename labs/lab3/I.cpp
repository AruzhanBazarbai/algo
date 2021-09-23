// Задача №111728. Левый и правый двоичный поиск
#include <iostream>
using namespace std;
// done

void find(int n,int * a,int x){
    int l=0,r=n-1,ind1=-1,ind2=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]<=x){
            ind1=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(a[ind1]!=x || ind1==-1) cout << 0 << endl;
    else{
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]>=x){
                ind2=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << ind2+1 << " " << ind1+1 << endl;

    }
}


int main(){
    int n,k,x;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<k;i++){
        cin >> x;
        find(n,a,x);
    }

    return 0;
}