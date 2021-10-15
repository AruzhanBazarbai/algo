#include <iostream>
#include <vector>
using namespace std;
// done
int main(){
    int q,l1,l2,r1,r2,n,cnt=0;
    cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        for(int i=0;i<n;i++){
            if((a[i]>=l1 && a[i]<=r1)||(a[i]>=l2 && a[i]<=r2)) cnt++;
        }
        cout << cnt << endl;
        cnt=0;

    }
    // cout << cnt;
    return 0;
}