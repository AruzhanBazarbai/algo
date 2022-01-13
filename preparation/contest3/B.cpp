// KMP
#include <iostream>
#include <vector>
using namespace std;
// done
vector<int> prefix_function(string s){
    int n=s.size();
    vector<int> p(n);
    p[0]=0;
    
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j>0 && s[j]!=s[i]){
            j=p[j-1];
        }
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int main(){
    string s,t;
    cin >> s;
    int q,l,r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        t=s.substr(l-1,r-l+1);
        string k=t+"#"+s;
        vector<int> v=prefix_function(k);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==t.size()) cnt++;
            // cout << v[i] << endl;
        }
        cout << cnt << endl;
    }
    
    
    return 0;
}