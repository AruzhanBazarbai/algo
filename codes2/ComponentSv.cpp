// /*
// Задача №111540 Компоненты связности
// Дан неориентированный невзвешенный граф. Необходимо посчитать количество его компонент связности и вывести их.

// Входные данные
// Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны по два числа i и j 
// (1 ≤ i, j ≤ N), которые означают, что вершины i и j соединены ребром.

// Выходные данные
// В первой строчке выходного файла выведите количество компонент связности. Далее выведите сами компоненты связности в следующем 
// формате: в первой строке количество вершин в компоненте, во второй - сами вершины в произвольном порядке.
// */
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
    
    while(m--){
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        
    }
    find_comp();

    if(vt.size()) cout << vt.size() << endl;
    for(int i=0;i<(int)vt.size();i++){
        if(vt[i].size()) cout << vt[i].size() << endl;
        for( int j=0;j<(int)vt[i].size();j++){
            cout << vt[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}