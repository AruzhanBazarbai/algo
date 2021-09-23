#include <iostream>
#include <vector>
using namespace std;
//binary search
int main(){
    int n,x;
    cin >> x;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l=0,r=n-1,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            res=mid;
            cout << "YES\n" << res;
            return 0;
        }
        if(a[mid]>x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << "NO\n";
    return 0;
}