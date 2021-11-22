// /*
// NAJPF - Pattern Find
// #kmp-algorithm
// Your task is so simple given a string and a pattern. You find the pattern on the given string. 
// If found print how many time found the pattern and their index. Otherwise print ‘Not Found’

// Input:          

// The input   line consists of a number T (1 ≤ T ≤ 50) test cases.

// For each case given two string number  A,B. the string and the pattern  1 ≤|A|, |B| ≤10^6

// All character will be lower case Latin character.  And |  | is the length of string.

// Output:

// For each case print the number  (found pattern from the given string) next line there position And Otherwise print 
// 'Not Found' without quota.
// There will a blank line between two cases.
// */
#include <iostream>
using namespace std;
// done
void prefix_f(string s,string t){
    string q=t+"#"+s;
    int n=q.size(),cnt=0;
    int a[n];
    a[0]=0;
    
    for(int i=1;i<n;i++){
        int j=a[i-1];
        while(j>0 && q[i]!=q[j]){
            j=a[j-1];
        }
        if(q[i]==q[j]){
            j++;
            if(j==t.size()) cnt++;
        }
        a[i]=j;
    }
    if(cnt>0){
        cout << cnt << endl;
        for(int i=0;i<n;i++){
            if(a[i]==t.size()) cout << i-2*t.size()+1 << " ";
            // cout << i << " " << a[i] << endl;
        }
    }
    else cout << "Not Found" ;

    cout << endl;
    // cout << endl;
}
int main(){
    int n;
    string s,t;
    cin >> n;
    while(n--){
        cin >> s >> t;
        prefix_f(s,t);
    }
}