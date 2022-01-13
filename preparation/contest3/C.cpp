#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t=n;
    long long p[5001];
    p[0]=1;
    for(int i=1;i<5001;i++) p[i]=p[i-1]*31;

    while(t--){
        string s;
        cin >> s;
        set<string> st;
        
        for(int i=0;i<s.size();i++){
            int t=st.size();
            st.insert(s.substr(0,i));
            st.insert(s.substr(i));
        }
    }
}