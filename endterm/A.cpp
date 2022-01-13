#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAX_INT 5e7
using namespace std;
// 
int n,m,v1,v2,e,x1,x2,x3,x4;

int used[100005],c[100005];
vector<pair<int,int> > g[100005];
vector<int> ans;
bool ok=false;
long long d[100005],d2[100005],d3[100005];

void f(int x){
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=1;i<=n;i++) d[i]=MAX_INT;
    d[x]=0;

    set<pair<long long,int> > st;
    for(int i=1;i<=n;i++)
    	st.insert(make_pair(d[i],i));

    while(!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        used[v]=true;
        for(int j=0;j<g[v].size();j++){ 
            if(!used[g[v][j].first]){ 
                if(d[g[v][j].first] > d[v]+g[v][j].second){ 
                    st.erase({d[g[v][j].first],g[v][j].first});
                    d[g[v][j].first] = d[v]+g[v][j].second; 
                    st.insert(make_pair(d[g[v][j].first],g[v][j].first));
                    // c[g[v][j].first]=v; 
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << c[i] << " " << d[i] << endl;

}


int main(){ 
    cin >> n >> m;
    while(m--){
        cin >> v1 >> v2 >> e;
        g[v1].push_back(make_pair(v2,e));
        g[v2].push_back(make_pair(v1,e));
    }
    cin >> x1 >> x2 >> x3 >> x4;
    f(x2);
    // for(int i=1;i<=n;i++) d2[i]=d[i];
    d2[x1]=d[x1];
    d2[x2]=d[x2];
    d2[x3]=d[x3];
    d2[x4]=d[x4];
    f(x3);
    d3[x1]=d[x1];
    d3[x2]=d[x2];
    d3[x3]=d[x3];
    d3[x4]=d[x4];
    // for(int i=1;i<=n;i++) d3[i]=d[i];
    f(x1);
    if(d[x1] == MAX_INT || d[x2] == MAX_INT || d[x3] == MAX_INT)
		cout << -1 << endl;
	// else cout << min(d[x3] + d2[x2] + d3[x4], d[x3] + d3[x2] + d2[x4]) << endl;
	else cout << min(d[x2] + d2[x3] + d3[x4], d[x2] + d3[x3] + d2[x4]) << endl;

    
    return 0;
}
