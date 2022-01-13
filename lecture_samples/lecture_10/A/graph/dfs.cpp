// dfs -нельзя найти кратчайший путь с помощб. дфс
// обход глубину
//можно найти компоненты связности 
#include <iostream>
#include <vector>
using namespace std;

int n,m,x,y,v;

int used[100];
vector<int> g[100];

void dfs(int v){ //O(n) n-количество ребер
    // cout << v << " ";
    used[v]=1;
    for(int i=0;i<g[v].size();i++){
        int y=g[v][i]; //все смежные вершины  с v
        if(used[y]==0){ //если not used то вызываем рекурсию
            dfs(y);
        }
    }
}


int main(){ 
    cin >> n >> m;
    int cnt=0;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // cin >> v;
    // dfs(v-1);
    for(int i=0;i<n;i++){ // находим компоненты связности //O(n)
        if(!used[i]){
            cnt++;
            dfs(i);
            
        }
    }
    
    return 0;
}
