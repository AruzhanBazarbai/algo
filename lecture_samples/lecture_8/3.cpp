// alternative to Rabin Karp
// дается подстрока s и строка t, нужно найти где подстрока s в t встречается 
#include <iostream> 
#include <vector>
using namespace std;
vector<int> prefix_function(string s){ //O(n)
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
    cin >> s >> t;
    string q=s+"#"+t;
    vector<int> v=prefix_function(q);
    cout << q << endl;
    for(int i=0;i<q.size();i++){
        if(v[i]==s.size()) cout << i-2*s.size() << " ";
    }
    return 0;
}