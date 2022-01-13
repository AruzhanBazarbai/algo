
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MXN 200005
bool used[MXN];
bool used_v[MXN];
vector<vector<int> > vt;
vector<int> t;
int n;
vector<int> g[MXN];
// 
void dfs(int v){
    // t.push_back(v);
    used[v]=true;

    for(int j=0;j<(int)g[v].size();j++){
        if(!used[g[v][j]] && !used_v[g[v][j]]){
            dfs(g[v][j]);
        }
    }
}
void find_comp(){
    for(int i=1;i<=n;i++){
        used[i]=false;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!used[i] && !used_v[i]){
            dfs(i);
            cnt++;
            
        }
    }
    cout << cnt << endl;
}

int main(){
    int m,i,j;
    cin >> n >> m;
    
    while(m--){
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        
    }
    
    for(int i=1;i<=n;i++){
        // cout << "i: " << i << endl; 
        int j=0;
        used_v[i]=true;
        while(j<g[i].size()){
            int y=g[i][j];
            // cout << "g[i][j]: " << y << endl;
            swap(g[i][j],g[i][g[i].size()-1]);
            g[i].pop_back();
            // g[i][j]=0;
            for(int k=0;k<g[y].size();k++){
                if(g[y][k]==i){
                    // cout << "g[y][k]: " << g[y][k] << endl;
                    swap(g[y][k],g[y][g[y].size()-1]);
                    g[y].pop_back();
                    break;
                    // g[y][k]=0;
                }
            }
        }
        find_comp();
    }

    return 0;
}