#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
int cycle_start,cycle_end;
int n,m,x,y;
int used[100005];
int cycle_used[100005];
vector<int> g[100005];
vector<int> ans;

bool cycle_find(int v){
    cycle_used[v]=1;
    for(int i=0;i<g[v].size();i++){
        int y=g[v][i];

        if(cycle_used[y]==0){
            if(cycle_find(y)) return true;

        }else if(cycle_used[y]==1){
            cycle_start=y;
            cycle_end=v;
            return true;
        }
    }
    cycle_used[v]=2;
    return false;
    
}

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
    
    cycle_start=-1;
    for(int i=1;i<=n;i++){
        if(!cycle_used[i]){
            if(cycle_find(i)){  
                break;
            } 
        }
        
    }
    if(cycle_start==-1){
        cout << "Possible" << endl;
        top_sort();
        for(int x : ans) cout << x << " ";
    }else{
        cout << "Impossible" << endl;
    }
    
    
    
    
    return 0;
}
