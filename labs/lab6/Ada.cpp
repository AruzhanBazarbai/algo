#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,t,k;
    string s;
    vector<long long> hashes,res;
    cin >> t;
    long long p_pow[100005];
    p_pow[0]=1;
    for(int i=1;i<100005;i++){
        p_pow[i]=p_pow[i-1]*31;
    }
    while(t--){
        cin >> n >> k;
        cin >> s;
        int cnt=0;
        
        for(int i=0;i<s.length()-k+1;i++){
            long long hash=0;
            string temp=s.substr(i,k);
            for(int j=0;j<k;j++){
                hash+=(temp[j]-'a'+1)*p_pow[j];
            }
            hashes.push_back(hash);
        }
        // long long hash=0;
        // for(int i=0;i<s.size();i++){
        //     hash+=(s[i]-'a'+1)*p_pow[i];
        //     hashes.push_back(hash);
        // }
        // for(int i=k-1;i<hashes.size();i++){
        //     long long h=hashes[i];
        //     if(i>=k){
        //         h-=hashes[i-2];
        //         // h*p_pow[s.size()-i];
        //     }
        //     res.push_back(h);
        // }
        sort(hashes.begin(),hashes.end());
        for(int i=0;i<hashes.size();i++){
            if(i==0 || hashes[i]!=hashes[i-1]){
                cnt++;
            }
        }
        hashes.clear();
        // res.clear();
        cout << cnt << endl;

    }
    
    return 0;
}