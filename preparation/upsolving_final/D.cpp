/*
Problem D. Cycled shifts
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
Keqing loves to solve some puzzles. Sometimes she comes up with different conditions and tries to find a
solution. This time the problem looks like this: given strings s and t of length n. Determine how many
right cyclic shifts are required to get string t from string s.
Input
The first line contains an integer n (1 ≤ n ≤ 100000), the length of strings.
The second line contains a string s.
The third line contains a string t.
Output
If t is not the cyclic shift of string s, print the −1.
In other case print the answer
*/
#include <iostream>
#include <vector>
using namespace std;
// done
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
    string s,t,q;
    int n;
    cin >> n;
    cin >> s >> t;
    q=s+'#'+t+t;
    vector<int> v=prefix_function(q);
    int ind;
    bool ok=false;
    for(int i=0;i<v.size();i++){
        if(v[i]==s.size()){
            ok=true;
            ind=i;
            break;
        }
        // cout << v[i] << " ";
    }
    
    if(ok){
        cout << ind-2*s.size();
    }else cout << -1;
    return 0;
}

/*
zabcd
abcdz
zabcd#abcdzabcdz
0 0 0 0 0 0 0 0 0 0 1  2  3  4  5  1
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
          #                      d    
4
*/
