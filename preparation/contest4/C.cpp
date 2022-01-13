/*
Problem C. Marios War
Input file: standard input
Output file: standard output
Time limit: 2 seconds
Memory limit: 256 megabytes
Here is the field, where each cell can have one of three values:
• "0 an empty cell;
• "1 a cell with the brown mushroom;
• "2 a cell with Mario.
Every minute, Mario crushes any brown mushroom that is adjacent to his position (up, down, top, bottom)
and new Mario appears instead of mushroom, Mario does not move to the empty cell.
How many minutes will it take for Mario to kill all brown mushrooms in each cell? The number of Marios
can be more than one. If this is impossible, return -1.
Input
The first line contains two integers, m - number of rows of a field, n - number of columns of a field
(1  m, n  1000). The following m lines contain n values (0, 1, or 2).
Output
Print the minimum time (in minutes) that must elapse until no cell will contain a brown mushroom. If
any mushroom is unreachable for every Mario in a field print -1
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// done
int n,m,cnt;
int used[1005][1005];
int d[1005][1005];
int a[1005][1005];

int bfs(int x,int y){ 
    used[x][y]=1;
    a[x][y]=2;
    queue<pair<int,int> > q1,q2;
    q1.push(make_pair(x,y));
    while(1){
        cnt++;
        while(!q1.empty()){
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            if(i-1>=0 && a[i-1][j]==1 && !used[i-1][j]){
                q2.push(make_pair(i-1,j));
                used[i-1][j]=1;
                a[i-1][j]=2;
            }
            if(j-1>=0 && a[i][j-1]==1 && !used[i][j-1]){
                q2.push(make_pair(i,j-1));
                used[i][j-1]=1;
                a[i][j-1]=2;
            }
            if(i+1<n && a[i+1][j]==1 && !used[i+1][j]){
                q2.push(make_pair(i+1,j));
                used[i+1][j]=1;
                a[i+1][j]=2;
            }
            if(j+1<m && a[i][j+1]==1 && !used[i][j+1]){
                q2.push(make_pair(i,j+1));
                used[i][j+1]=1;
                a[i][j+1]=2;
            }


        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        if(q1.empty()) return cnt;
        

    }
   
    cnt++;
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }  
    }
    int cnt_max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j] && a[i][j]==2){
                cnt=0;
                int x=bfs(i,j);
                if(cnt_max<cnt) cnt_max=cnt;
            }
        }
    }
    bool k=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1 && !used[i][j]){
                k=false;
            }
        }
    }
    if(k) cout << cnt_max-1;
    else cout << -1;

    return 0;
}