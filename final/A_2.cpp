#include <iostream>
using namespace std;
// done
long long n,k,a[111111],maxx;

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxx=max(a[i],maxx); //1 
    }
    long long l=maxx,r=1e16; //2 
    while(r>l){
        long long m=(r+l)/2,cnt=1,sum=0; //52,28,15,24,22
        for(int i=1;i<=n;i++){
            if(sum+a[i]>m){ //3
                cout <<"sum: " << sum << " a[i]: " << a[i] << " mid: " << m << " r: "<< r << " l: " << l << endl ;
                cnt++;
                sum = 0;
            }
            sum+=a[i]; //
            // cout << sum << " ";
        }
        if(cnt>k) //
            l=m+1;
        else 
            r=m; //
    }
    cout << l;
}