/*
Problem A. Happy Birthday
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
Dariga’s birthday is coming soon and she wants to invite n different friends to her birthday. There are
m pairs of people who, if the first one doesn’t come to the birthday, the second one also will not come
and in the same way for the second one(unoriented). As far as it’s quarantine she wants to minimize the
number of people who will come to her birthday, meanwhile she does not want to be alone. Print what is
the minimum number of people she can invite to the birthday, so that at least there will be one person in
birthday
Input
The first line contains two integers n, m (1 <= n <= 100000, 1 <= m <= 100000) — the number of
people and pairs of people who wants to be together in birthday The next m lines contains two integers
(1 <= a[i],b[i] <= n) that means a[i] and b[i] are close friends
Output
Print the minimum number of people she invite to the birthday
Examples

5 4
1 2
2 3
3 1
4 5

2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MXN 100005
bool used[MXN];
vector<vector<int> > vt;
vector<int> t;
int n;
vector<int> g[MXN];
// done
void dfs(int v){
    t.push_back(v);
    used[v]=true;

    for(int j=0;j<(int)g[v].size();j++){
        if(!used[g[v][j]]){
            dfs(g[v][j]);
        }
    }
}
void find_comp(){
    for(int i=1;i<=n;i++){
        if(!used[i]){
            t.clear();
            dfs(i);
            vt.push_back(t);
        }
    }
}

int main(){
    int m,i,j;
    cin >> n >> m;
    
    while(m--){
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        
    }
    find_comp();
    int min=1e7;
    for(int i=0;i<(int)vt.size();i++){
        if(min>vt[i].size()){
            min=vt[i].size();
        }
    }
    cout << min << endl;
    return 0;
}