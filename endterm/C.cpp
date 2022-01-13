#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 
int cycle_start,cycle_end;
int n,m,x,y;
int used[105];
int cycle_used[105];
int a[105][105];
vector<int> g[105];
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

int main(){ 
    cin >> n >> m;
    for(int i=0;i < m;i++){
        cin >> x >> y;
        g[x].push_back(y);
        
    }
    
    cycle_start=-1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!cycle_used[i]){
            if(cycle_find(i)){  
                cnt++;
            } 
        }
    }
    cout << cnt << endl;
    if(cnt<=1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
