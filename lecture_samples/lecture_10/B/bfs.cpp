#include <iostream>
#include <queue>
using namespace std;
#define MXN 100
bool used[MXN];
int a[MXN][MXN];
int n;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    queue<int> q;
    q.push(0);
    used[0]=true;
    cout << 0 << " ";

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(a[cur][j]==1 && !used[j]){
                q.push(j);
                used[j]=true;
                cout << j << " ";
            }
        }
    }

}