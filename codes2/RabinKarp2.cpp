#include <iostream>
using namespace std;
int main(){ //O(n+m)
    string s,t;
    cin >> s >> t;
    int p=31,n=s.size(),m=t.size();
    long long h[n];
    long long p_pow[n];
    long long hash=0;
      
    p_pow[0]=1;
    for(int i=1;i<n;i++) p_pow[i]=p_pow[i-1]*p;

    for(int i=0;i<n;i++){
        h[i]=(s[i]-'a'+1)*p_pow[i];
        if(i!=0) h[i]+=h[i-1];
    }
    for(int i=0;i<m;i++){
        hash+=(t[i]-'a'+1)*p_pow[i];
    }
    for(int i=0;i+m-1<n;i++){
        long long h1=h[i+m-1];
        if(i) h1-=h[i-1];
        
        if(hash*p_pow[i]==h1){
            cout << i << " ";
        }
    }
    return 0;

}