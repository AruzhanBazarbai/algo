// даются две строки s и t. Нужно найти является ли s циклическим сдвигом t  
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
    string q=s+"#"+t+t;
    vector<int> v=prefix_function(q);
    cout << q << endl;
    bool k=false;
    for(int i=0;i<q.size();i++){
        if(v[i]==s.size()){
            k=true;
            break;
        }
    }
    cout << ((k)?"YES":"NO");
    return 0;
}