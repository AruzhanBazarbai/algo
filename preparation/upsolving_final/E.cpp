#include <iostream>
#include <vector>
#define MAX_INT 1e7
using namespace std;
int n,m,x,y,l;
pair<int,int> g[1005];
int u[1005];
int c[1005]; 
vector<int> d(1005,MAX_INT);

int dj(int x){
    for(int i=x;i<=n;i++) u[i]=0;
    for(int i=x;i<=n;i++) d[i]=MAX_INT;

    d[x]=0;
    int mini=MAX_INT;
    for(int i=1;i<=n;i++){
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!u[j] && (v==-1 || d[v]>d[j])){ 
                v=j;
            }
        }
        // cout << v+1 << endl;
        u[v]=true; 

        for(int j=1;j<=n;j++){ 
            if(!u[j]){ 
                if(d[j] > d[v]+(abs(g[v].first-g[j].first)+abs(g[v].second-g[j].second))){ 
                    d[j] = d[v]+(abs(g[v].first-g[j].first)+abs(g[v].second-g[j].second)); 
                    c[j]=v; 
                    if(mini>d[j] && d[j]!=0) mini=d[j];
                }
            }
        }
        
    }
    if(mini==MAX_INT) return 0;
    return mini;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        g[i]=make_pair(x,y);
    }
    
    int maxi=-1;
    for(int i=1;i<=n;i++){
        int a=dj(i);
        if(maxi<a) maxi=a;
    }
    cout << maxi;

    return 0;

}