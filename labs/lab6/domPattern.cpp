
#include <iostream>
#include <vector>
using namespace std;
// 
int main(){
    int n;
    string s;
    long long p_pow[1000005];
    vector<pair<long long,int> > hashes;
    vector<pair<pair<long long,string>,int> > hash;
    p_pow[0]=1;
    for(int i=1;i<1000005;i++) p_pow[i]=p_pow[i-1]*31;
    while(1){
        cin >> n;
        if(n==0) break;
        while(n--){
            cin >> s;
            long long h=0;
            for(int i=0;i<s.size();i++){
                h+=(s[i]-'a'+1)*p_pow[i];
            }
            hash.push_back(make_pair(make_pair(h,s),0));
            
        }
        cin >> s;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            hashes.push_back(make_pair((s[i]-'a'+1)*p_pow[i],i));

            if(i) hashes[i].first+=hashes[i-1].first;
            for(int j=0;j<hash.size();j++){
                if(i-hash[j].first.second.size()+1>=0){
                    long long h1=hashes[i].first;
                    if(i-hash[j].first.second.size()+1>0){
                        h1-=hashes[i-hash[j].first.second.size()].first;
                    }

                    if(hash[j].first.first*p_pow[i-hash[j].first.second.size()+1]==h1){
                        hash[j].second++;
                        if(hash[j].second>maxi){
                            maxi=hash[j].second;
                        }
                    }

                }else{
                    continue;
                }
            }
            cout << maxi << endl;
            for(int i=0;i<hash.size();i++){
                if(hash[i].second==maxi) cout << hash[i].first.second << endl;
            }
            hash.clear();
            hashes.clear();
        }

    }
    return 0;

}