#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// 
int f1(int x){
    return x*2;
}
int f2(int x){
    if(x>1) return x-1;
}

int main(){
    int x ,y,n,m;
    cin >> x >> y;
    vector<int> ans;
    if(x>y){
        while(x>y){
            ans.push_back(x);
            x--;
        }
        cout << ans.size() << endl;
        for(int x: ans) cout << x << " ";
        return 0;
    }
    queue<int> q;
    map<int,int> path,distance;
    
    q.push(x);
    path[x]=-1;
    distance[x]=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        int a=f1(v);
        int b=f2(v);
        if(path.count(a)==0){
            path[a]=v;
            distance[a]=distance[v]+1;
            q.push(a);
        }
        if(path.count(b)==0){
            path[b]=v;
            distance[b]=distance[v]+1;
            q.push(b);
        }
        if(a==y || b==y){
            int i=distance[y];
            cout << i << endl;
            int temp=y;
            while(path[temp]!=-1){
                ans.push_back(temp);
                temp=path[temp];
            }
            reverse(ans.begin(),ans.end());
            for(int x: ans) cout << x << " ";
            break;
        }
    }

}