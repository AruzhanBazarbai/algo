// algorithm of prefix function
#include <iostream>
using namespace std;
int a[1000005];
void prefix_function(string s){ //O(n)
    int n=s.size();
    
    for(int i=1;i<n;i++){
        int j=a[i-1];
        while(j>0 && s[j]!=s[i]){
            j=a[j-1];
        }
        if(s[i]==s[j]) j++;
        a[i]=j;
    }
}
int main(){
    string s;
    cin >> s;
    prefix_function(s);
    for(int i=0;i<s.size();i++){
        cout << a[i] << " ";
    }
    return 0;
}