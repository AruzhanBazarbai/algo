// bfs- если граф невзвешенный.можно обходить по ширине
// можно найти кратчайший путь
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,x,y,v;

int used[100];
int d[100]; // находим сколько расстоянии до вершин определенной,т.е. находим кратчайший путь
vector<int> g[100];

void bfs(int v){
    queue<int> q;
    used[v]=1;
    q.push(v);
    d[v]=0;
    while(!q.empty()){
        int x=q.front(); //берем текушую то вершину которая  в очереди
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i]; // пробегаемся фориком и добавляем все вершины, которые с ней связаны в очередь
            if(used[y]==0){
                q.push(y); // если not used то добавляем ее в очередь
                used[y]=1; //и делаем used
                d[y]=d[x]+1; //d[y]-новая вершина d[x]-вершина от которой пришли
            }
        }
        q.pop(); //удаляем текущую вершину с очереди
    }
    


}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> v;
    bfs(v-1);
    for(int i=0;i<n;i++){
        cout << d[i] << " ";
    }
    return 0;
}