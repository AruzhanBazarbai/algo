#include <iostream>
#include <vector>
using namespace std;
// 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    string s;
    long long p_pow[1000005];
    vector<long long> hashes;
    vector<pair<pair<long long,string>,int> > hash;
    p_pow[0]=1;
    for(int i=1;i<1000005;i++){
        p_pow[i]=p_pow[i-1]*31;
    }
    while(1){
        cin >> n;
        if(n==0) break;
        while(n--){
            cin >> s;
            long long h=0;
            int k=s.size();
            for(int i=0;i<k;i++){
                h+=(s[i]-'a'+1)*p_pow[k-i-1];
            }
            hash.push_back(make_pair(make_pair(h,s),0));
            
        }
        cin >> s;
        int m=s.size();
        int maxi=0;
        hashes[0]=0;
        for(int i=0;i<m;i++){
            hashes[i]+=(s[i]-'a'+1)*p_pow[m-i-1];
            // hashes[i-k+1]=(hashes[i-k]-(s[i-k]-'a'+1)*p[k-1])*pr+(s[i]-'a'+1);
            for(int j=0;j<hash.size();j++){
                int t=hash[i].first.second.size();
                if(t>i+1) continue;
                else{
                    if(t<=i){
                        long long h=(hashes[i-t]-(s[i-t]-'a'+1)*p_pow[t-1])*31+(s[i]-'a'+1);
                    }
                }

            }

        }
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}