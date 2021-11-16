// algorithm of prefix function
#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    int n=s.size();
    vector<int> p(n);
    
    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            if(s.substr(0,k)==s.substr(i-k+1,k)){
                p[i]=k;
            }
        }
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