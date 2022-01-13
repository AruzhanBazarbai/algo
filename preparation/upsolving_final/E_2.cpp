#include <iostream>
#include <vector>
#define MAX_INT 1e7
using namespace std;
int n,m,x,y,l;
pair<int,int> g[1005];
int u[1005];
int c[1005]; 
vector<int> d(1005,MAX_INT);

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        g[i]=make_pair(x,y);
    }
    
    int maxi=-1;
    for(int i=1;i<=n;i++){
        int mini=MAX_INT;
        for(int j=i+1;j<=n;j++){
            int a=abs(g[i].first-g[j].first)+abs(g[i].second-g[j].second);
            if(mini>a) mini=a;
            // cout << mini << " ";
        }
        if(maxi<mini && mini!=MAX_INT) maxi=mini;
        // cout << maxi << " ";
        // cout << endl;
    }
    if(maxi!=-1) cout << maxi;
    else cout << 0;

    return 0;

}