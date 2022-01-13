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
    string s,t,res;
    cin >> s;
    bool ok=false;
    for(int i=1;i<s.size();i++){
        int cnt=0;
        t=s.substr(0,i);
        string q=t+"#"+s;
        vector<int> v=prefix_function(q);
        if(v[t.size()*2]==t.size() && v[q.size()-1]==t.size()) cnt=2;
        for(int i=0;i<v.size();i++){
            if(v[i]==t.size() && i>t.size()*2 && i<(q.size()-t.size())){
                cnt++;
                res=t;
                break;
            }
        }
        if(cnt==3){
            ok=true;
            break;
        }
    }
    if(ok) cout << res << endl;
    else cout << "Just a legend" << endl;
    
    return 0;
}
