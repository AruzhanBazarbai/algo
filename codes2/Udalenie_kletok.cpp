/*
Задача №652. Удаление клеток
Из прямоугольного листа клетчатой бумаги (M строк, N столбцов) удалили некоторые клетки. 
На сколько кусков распадётся оставшаяся часть листа? Две клетки не распадаются, если они имеют общую сторону.

Входные данные
В первой строке находятся числа M и N, в следующих M строках - по N символов. Если клетка не была вырезана, 
этому соответствует знак #, если вырезана - точка. 1 <= M, N <= 100.

Выходные данные
Вывести одно число.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 1e7
using namespace std;
// done
int n,m,x,y;

int used[105][105],c[105];
char g[105][105];
vector<int> d(105,MAX_INT);

void dfs(int i,int j){ 
    used[i][j]=1;
    if(i-1>=0 && g[i-1][j]=='#' && !used[i-1][j])  dfs(i-1,j);
    if(j-1>=0 && g[i][j-1]=='#' && !used[i][j-1]) dfs(i,j-1);
    if(i+1<n && g[i+1][j]=='#' && !used[i+1][j]) dfs(i+1,j);
    if(j+1<m && g[i][j+1]=='#' && !used[i][j+1]) dfs(i,j+1);
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j] && g[i][j]=='#'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
