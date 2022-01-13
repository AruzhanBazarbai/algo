// /*
// Задача №161. Один конь
// Максимальное время работы на одном тесте:	1 секунда
// На шахматной доске NxN в клетке (x1, y1) стоит голодный шахматный конь. Он хочет попасть в клетку (x2, y2), 
// где растет вкусная шахматная трава. Какое наименьшее количество ходов он должен для этого сделать?

// Входные данные
// На вход программы поступает  пять чисел: N, x1, y1, x2, y2 (5 <= N <= 20, 1 <= x1, y1, x2, y2 <= N). 
// Левая верхняя клетка доски имеет координаты (1, 1), правая нижняя - (N, N).

// Выходные данные
// В первой строке выведите единственное число K - наименьшее необходимое число ходов коня. В каждой из следующих K+1 строк 
// должно быть записано 2 числа - координаты очередной клетки в пути коня.

// 4
// 3 3
// 2 1
// 1 3
// 3 2
// 5 1
// */
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 1e7

using namespace std;
// done
int n,x1,y1,x2,y2;
int used[105][105];
int d[105][105];
int a[105][105];
pair<int,int> c[105][105];
vector<pair<int,int> > ans;

void init(){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            d[i][j]=MAX_INT;
        }
    }
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            c[i][j]=make_pair(-1,-1);
        }
    }
}
int main(){ 
    cin >> n >> x1 >> y1 >> x2 >> y2;

    init();

    d[x1][y1]=0;
    for(int i=1;i<=n*n;i++){
        int v=-1;
        int x=-1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(!used[j][k] && ((v==-1 && x==-1) || d[v][x]>d[j][k])){ 
                    v=j;
                    x=k;
                }
            }
        }
        used[v][x]=true; 

        for(int j=1;j<=n;j++){ 
            for(int k=1;k<=n;k++){
                if(j==v && k==x) continue;
                if(!used[j][k] && d[j][k]>d[v][x]+1 && abs((j-v)*(k-x))==2){
                    d[j][k]=d[v][x]+1;
                    c[j][k]=make_pair(v,x);
                }
            }
        }
    }
    int cnt=d[x2][y2];
    int temp1=x2,temp2=y2;
    while(cnt--){
        ans.push_back(c[temp1][temp2]);
        int a=c[temp1][temp2].first;
        int b=c[temp1][temp2].second;
        temp1=a;
        temp2=b;
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    cout << x2 << " " << y2 << endl;;

    return 0;
}
