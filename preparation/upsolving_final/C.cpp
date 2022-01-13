/*
Problem C. Ashira and kingdom
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
In the kingdom of Ashura there are many cities connected by a special chakra. As the next great war of
all shinobi begins, Ashura wants to share his chakra so that all cities have contact with each other. Any
two cities have contact with each other, if from one city you can get to another through a special chakra.
What is the smallest number of cities Ashura needs to connect so that he spends as little special chakra
as possible?
Input
In the input you are given n and m (1 ≤ n, m ≤ 100). The number of cities and the amount of special
chakra between cities. The next m lines contain x, y (1 ≤ x, y ≤ 100) indicating that cities x and y are
connected by a special chakra
Output
Print the number of cities that should be connected
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MXN 1005
bool used[MXN];
vector<vector<int> > vt;
vector<int> t;
int n,cnt;
vector<int> g[MXN];
// done
void dfs(int v){
    // t.push_back(v);
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
            // t.clear();
            cnt++;
            dfs(i);
            // vt.push_back(t);
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
    cnt=0;
    find_comp();

    // if(vt.size()) cout << vt.size() << endl;
    // for(int i=0;i<(int)vt.size();i++){
    //     if(vt[i].size()) cout << vt[i].size() << endl;
    //     for( int j=0;j<(int)vt[i].size();j++){
    //         cout << vt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << cnt-1 << endl;
    return 0;
}