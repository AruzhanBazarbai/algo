#include <iostream>
using namespace std;
int pre_l;
// done

int prefix_function(string s){
    int n=s.size();
    int a[n];
    for(int i=0;i<n;i++) a[i]=0;
    
    for(int i=1;i<n;i++){
        int j=a[i-1];
        while(j>0 && s[j]!=s[i]){
            j=a[j-1];
        }
        if(s[i]==s[j]) j++;
        a[i]=j;
    }
    int cnt=0;
    // for(int i=0;i<n;i++){
    //     // cout << a[i] << " ";
    //     if(a[i]==k.size()) cnt++;
    // }
    // cout << endl;
    pre_l=a[n-1];
    return a[n-1];
}
int main(){
    int n,k;
    string s;
    cin >> n;
    while(n--){
        cin >> s >> k;
        string t=s+'#';
        int ind=0;
        int a=prefix_function(s);
        long long n = s.size();
        cout << n+(n-a)*(k-1) << endl;
    }
    
    return 0;
}