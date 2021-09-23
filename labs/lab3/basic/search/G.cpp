// Задача №4. Двоичный поиск
#include <iostream>
using namespace std;
//done
int find(int n,int * a,int x){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x) return 1;
        else if(a[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return 0;
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
        if(find(n,a,x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}