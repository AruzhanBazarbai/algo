// нужно найти хеш всех строк, сортировать и сгруппировать по одинаковым строкам
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        s[i]=x;
    }
    int p=31;
    long long p_pow[10000];
    p_pow[0]=1;
    for(int i=1;i<10000;i++) p_pow[i]=p_pow[i-1]*p;
    pair<long long,int> hashes[n];

    for(int i=0;i<n;i++){
        long long hash=0;
        for(int j=0;j<s[i].size();j++){
            hash+=(s[i][j]-'a'+1)*p_pow[j];
        }
        hashes[i]=make_pair(hash,i);
    }
    sort(hashes,hashes+n);

    for(int i=0,group=0;i<n;i++){
        if(i==0 || hashes[i].first!=hashes[i-1].first){
            cout << "\nGroup" << ++group << " " << s[hashes[i].second] << " :";
        }
        cout << " " << hashes[i].second;
    }
    return 0;
}