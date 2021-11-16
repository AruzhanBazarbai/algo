// KMP
#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    int n=s.size();
    vector<int> p(n);
    p[0]=0;
    
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j>0 && s[j]!=s[i]){
            j=p[i-1];
        }
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int main(){
    string s;
    cin >> s;
    vector<int> v=prefix_function(s);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}