#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MXN 100005
bool used[MXN];
vector<vector<int> > vt;
vector<int> t;
int n;
vector<int> g[MXN];
bool usedComp[1005];
// done
void dfs(int v){
    t.push_back(v);
    used[v]=true;

    for(int j=0;j<(int)g[v].size();j++){
        if(!used[g[v][j]]){
            dfs(g[v][j]);
        }
    }
}
void find_comp(){
    for(int i=1;i<=n;i++){
        if(!used[i]){
            t.clear();
            dfs(i);
            vt.push_back(t);
        }
    }
}

int main(){
    int m,i,j;
    cin >> n >> m;
    vector<vector<int> > ans1,ans2,ans3;
    
    while(m--){
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        
    }
    find_comp();
    int cnt_1=0,cnt_2=0,cnt_3=0;
    for(int i=0;i<(int)vt.size();i++){
        if(vt[i].size()>3){
            cout << -1 << endl;
            return 0;
        }
        if(vt[i].size()==1){
            cnt_1++;
            ans1.push_back(vt[i]);
        }
        else if(vt[i].size()==2){
            cnt_2++;
            ans2.push_back(vt[i]);
        }
        else{
            cnt_3++;
            ans3.push_back(vt[i]);
        }
    }
    if(cnt_1>=cnt_2){
        for(int i=0;i<cnt_2;i++){
            ans2[i].push_back(ans1[cnt_1-1][0]);
            ans1.pop_back();
            cnt_1--;
        }
        if(cnt_1%3==0){
            int ind=0;
            while(cnt_1>0){
                vector<int> temp;
                temp.push_back(ans1[ind][0]);
                temp.push_back(ans1[ind+1][0]);
                temp.push_back(ans1[ind+2][0]);
                ans2.push_back(temp);
                ind+=3;
                cnt_1-=3;
            }
        }else{
            cout << -1 << endl;
        }
        for(int i=0;i<cnt_3;i++){
            ans2.push_back(ans3[i]);
        }
        for(int i=0;i<ans2.size();i++){
            for(int j=0;j<ans2[i].size();j++){
                cout << ans2[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << -1<< endl;
    }
    return 0;
}