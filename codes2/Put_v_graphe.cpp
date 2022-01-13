/*
Задача №160. Путь в графе_0
Максимальное время работы на одном тесте:  	5 секунд
В неориентированном графе требуется найти минимальный путь между двумя вершинами.

Входные данные
Первым на вход поступает число N – количество вершин в графе (1 ≤ N ≤ 100). 
Затем записана матрица смежности (0 обозначает отсутствие ребра, 1 – наличие ребра). Далее задаются номера двух вершин – 
начальной и конечной.

Выходные данные
Выведите сначала L – длину кратчайшего пути (количество ребер, которые нужно пройти), а потом сам путь. Если путь имеет длину 0, 
то его выводить не нужно, достаточно вывести длину.

Необходимо вывести путь (номера всех вершин в правильном порядке). Если пути нет, нужно вывести -1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 1e7
using namespace std;
// done
int n,m,x,y;

int used[105],c[105];
int g[105][105];
vector<int> ans;
bool ok=false;
vector<int> d(105,MAX_INT);


int main(){ 
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }
    cin >> x >> y;
    d[x]=0;
    for(int i=1;i<=n;i++){
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!used[j] && (v==-1 || d[v]>d[j])){ 
                v=j;
            }
        }
        used[v]=true; 

        for(int j=1;j<=n;j++){ 
            if(!used[j] && g[v][j]>0){ 
                if(d[j] > d[v]+g[v][j]){ 
                    d[j] = d[v]+g[v][j]; 
                    c[j]=v; 
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << c[i] << " " << d[i] << endl;
    if(d[y]==MAX_INT && c[y]==0) cout << -1 << endl;
    else if(c[y]==0 && d[y]==0) cout << 0 << endl;
    else{
        int cnt=d[y];
        int temp=y;
        while(cnt--){
            ans.push_back(c[temp]);
            temp=c[temp];
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(int x:ans) cout << x << " ";
        cout << y;
        
    }

    
    return 0;
}
