#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    long long p[50000];
    p[0]=1;
    for(int i=1;i<50000;i++) p[i]=p[i-1]*31;
    long long hashes[s.size()];
    long long h=0;
    for(int i=0;i<t.size();i++){
        h+=(t[i]-'a'+1)*p[i];
    }

    for(int i=0;i<s.size();i++){
        hashes[i]=(s[i]-'a'+1)*p[i];
        if(i) hashes[i]+=hashes[i-1];
        if(i>=t.size()-1){
            long long cur_h=hashes[i];
            if(i-t.size()+1>0) cur_h-=hashes[i-t.size()];
            if(cur_h==h*p[i-t.size()+1]) cout << i+1-t.size() << " ";
        }
    }
}