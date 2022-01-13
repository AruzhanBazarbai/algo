#include <iostream>
using namespace std;
#define MXN 100
bool used[MXN];
int a[MXN][MXN];
int n;

void dfs(int v){
    used[v]=true;
    cout << v << " ";
    for(int j=0;j<n;j++){
        if(a[v][j]==1 && !used[j]){
            dfs(j);
        }
    }

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    dfs(0);
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(a[i][j]==1) cnt++;
    //     }
    // }
    // cout << cnt << endl; //количесво ребер

}