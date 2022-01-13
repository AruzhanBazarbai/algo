// /*
// Ada the Ladybug has decided to do some "Spring Cleaning". As you might know, she keeps a TODO list. 
// She is very sparing so she keeps all her activities as one string. You might get very confused while reading the string but she has a 
// system - every activity has length exactly K characters. Sadly, as new activities were added to the list many duplicities appeared. 
// Now it is time to find out how many unique activities are in her TODO list.
// Input
// First line contains T, number of test-cases.
// Each test-case begins with N, K, 1 ≤ K ≤ N ≤ 105, length of string and length of activites respectively.
// Next line consists of string of length N, consisting of lowercase letters.
// The sum of lengths of strings among all test-cases won't exceed 3*105
// Output
// For each test-case, print the number of unique substrings of length K
// Example Input
// 5
// 3 2
// aaa
// 5 1
// abcba
// 4 2
// abac
// 10 2
// abbaaaabba
// 7 3
// dogodog
// Example Output
// 1 3 3 4 4
// */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
long long p[100005];
int pr=31;
void hash_f(string s,int n,int k){
    int t=n-k+1;
    long long hashes[t];
    hashes[0]=0;
    for(int i=0;i<k;i++){
        hashes[0]+=(s[i]-'a'+1)*p[k-i-1];
    }
    for(int i=k;i<n;i++){
        hashes[i-k+1]=(hashes[i-k]-(s[i-k]-'a'+1)*p[k-1])*pr+(s[i]-'a'+1);
    }
    sort(hashes,hashes+t);
    int cnt=1;
    for(int i=1;i<t;i++){
        if(hashes[i]!=hashes[i-1]) cnt++;
    }
    cout << endl << cnt << endl;
}

int main(){
    p[0]=1;
    for(int i=1;i<100005;i++) p[i]=p[i-1]*pr;

    int t,n,k;
    cin >> t;
    string s;
    while(t--){
        cin >> n >> k;
        cin >> s;
        hash_f(s,n,k);
    }
    
    return 0;
}