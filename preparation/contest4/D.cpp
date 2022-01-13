/*
Problem D. Zarobek entered KBTU
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
Zarobek is currently first-year student at KBTU University. He just entered the University and he does
not yet know which subjects in what order should be taken. He knows for each subject what prerequisites
are required to take the subject. He needs to know in what order the subjects should be learned, so when
taking the subject all prerequisites should be taken before. Help him to find order so he take diploma at
the end
Input
The first line contains two integers n, m (1 <=n<= 100000, 1 <=m<= 100000) — the number of subjects
and pairs of prereqisites The next m lines contains two integers id of the subject (1 <= a[i], b[i] <= n)
that means a[i] is prerequisite of b[i]
Output
Print one line the order in which the subjects should be learned. Its guaranteed that there wouldn’t be
any cycle
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
int cycle_start,cycle_end;
int n,m,x,y;
int used[105];
vector<int> g[100005];
vector<int> ans;

void dfs(int v){ 
    used[v]=1;
    for(int i=0;i<g[v].size();i++){
        int y=g[v][i]; 
        if(used[y]==0){ 
            dfs(y);
        }
    }
    ans.push_back(v);
}

void top_sort(){
    for(int i=1;i<=n;i++){ 
        if(!used[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
}


int main(){ 
    cin >> n >> m;
    for(int i=0;i < m;i++){
        cin >> x >> y;
        g[x].push_back(y);
        
    }
    top_sort();
    for(int x: ans) cout << x << " ";
    return 0;
}
