// /*
// DISUBSTR - Distinct Substrings
// #suffix-array-8
// Given a string, we need to find the total number of its distinct substrings.

// Input
// T- number of test cases. T<=20;
// Each test case consists of one string, whose length is <= 1000

// Output
// For each test case output one number saying the number of distinct substrings.

// Example
// Sample Input:
// 2
// CCCCC
// ABABA

// Sample Output:
// 5
// 9

// Explanation for the testcase with string ABABA:
// len=1 : A,B
// len=2 : AB,BA
// len=3 : ABA,BAB
// len=4 : ABAB,BABA
// len=5 : ABABA
// Thus, total number of distinct substrings is 9.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
int prefix_f(string s){
    int n=(int)s.size(),cnt=0;
    vector<int> pi(n+1);
    for(int i=0;i<n;i++){
        pi[1]=0;
        int len=0;
        int maxi=0;
        for(int j=1;j<s.size();j++){
            while(true){
                if(s[j]==s[len]){
                    len++;
                    break;
                }
                if(len==0) break;
                len=pi[len];
            }
            pi[j+1]=len;
            maxi=max(len,maxi);
        }
        cnt+=(int)s.size()-maxi;
        s.erase(s.begin());
        
    }
    // for(int x:pi) cout << x << " ";
    // cout << endl;
    return cnt;

}
int main(){
    string s;
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        int cnt=prefix_f(s);
        cout << cnt << endl;
    }
    return 0;
}