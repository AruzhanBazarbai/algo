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
    int cnt=0;
    for(int i=1;i<s.size()/2;i++){
        t=s.substr(0,i);
        vector<int> v=prefix_function(t+"#"+s);
        if(v[t.size()*2]==t.size() && v[t.size()*3]==t.size()) cnt++;
    }
    cout << cnt;
    
    return 0;
}
