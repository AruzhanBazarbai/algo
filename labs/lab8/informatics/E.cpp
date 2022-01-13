/*
Задача №111541. Баобаб
Дан неориентированный невзвешенный граф. Необходимо определить, является ли он деревом.

Входные данные
В первой строке входного файла содержится одно натуральное число N (N ≤ 100) - количество вершин в графе. 
Далее в N строках по N чисел - матрица смежности графа: в i-ой строке на j-ом месте стоит 1, если вершины i и j 
соединены ребром, и 0, если ребра между ними нет. На главной диагонали матрицы стоят нули. 
Матрица симметрична относительно главной диагонали.

Выходные данные
Вывести "YES", если граф является деревом, и "NO" иначе.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MXN 105
bool used[MXN];
bool ok=false;
int n,cnt_comp=0;
int a[100][100];
// done
void dfs(int v){
    used[v]=true;
    for(int j=0;j<n;j++){ 
        if(a[v][j]==1 && !used[j]){
            dfs(j);
        }
    }
}
void find_comp(){
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs(i);
            cnt_comp++;
            
        }
    }
}

int main(){
    int x;
    cin >> n;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==1) cnt++;
        }
    }
    find_comp();
    if(n-1==cnt/2 && cnt_comp==1) cout << "YES";
    else cout << "NO";
    return 0;
}