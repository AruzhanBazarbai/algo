
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 1e7
using namespace std;
// done
int n,m;

int used1[405],used2[405],c[405];
int g1[405][405];
int g2[405][405];
vector<int> ans;
bool ok=false;
vector<int> d1(405,MAX_INT);
vector<int> d2(405,MAX_INT);

int main(){ 
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g1[i][j]=1;
        }
    }
    while(m--){
        int x,y;
        cin >> x >> y;
        // if(x!=1 && y!=n){
        //     g1[x][y]=0;
        //     g1[y][x]=0;
        // }
        g1[x][y]=0;
        g1[y][x]=0;
        g2[x][y]=1;
        g2[y][x]=1;

    }
    d1[1]=0;
    for(int i=1;i<=n;i++){
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!used1[j] && (v==-1 || d1[v]>d1[j])){ 
                v=j;
            }
        }
        used1[v]=true; 

        for(int j=1;j<=n;j++){ 
            if(!used1[j] && g1[v][j]>0){ 
                if(d1[j] > d1[v]+1){ 
                    d1[j] = d1[v]+1; 
                }
            }
        }
    }
    d2[1]=0;
    for(int i=1;i<=n;i++){
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!used2[j] && (v==-1 || d2[v]>d2[j])){ 
                v=j;
            }
        }
        used2[v]=true; 

        for(int j=1;j<=n;j++){ 
            if(!used2[j] && g2[v][j]>0){ 
                if(d2[j] > d2[v]+1){ 
                    d2[j] = d2[v]+1; 
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << d1[i] << " ";
    // cout << endl;
    // for(int i=1;i<=n;i++) cout << d2[i] << " ";
    // cout << endl;
    if(d1[n]==MAX_INT || d2[n]==MAX_INT) cout << -1 << endl;
    else cout << max(d1[n],d2[n]);

    
    return 0;
}
