#include <iostream> 
#include <vector> 
#include <cmath> 
#define MAX_INT 1e7 
using namespace std; 
int g[100][100]; 
int u1[100]; 
int c1[100]; 
vector<int> d1(100, MAX_INT); 
int u2[100]; 
int c2[100]; 
vector<int> d2(100, MAX_INT); 
 
int main(){ 
    int n, m, x, y; 
    cin >> n >> m; 
 
    int t[n][n]; 
    int r[n][n]; 
 
    for(int i=0; i<n; i++){ 
        for(int j=0; j<n; j++){ 
            t[i][j] = 0; 
            r[i][j] = 1; 
        } 
    } 
 
    for(int i=0; i<m; i++){ 
        cin >> x >> y; 
        t[x][y] = 1; 
        t[y][x] = 1; 
        r[x][y] = 0; 
        r[y][x] = 0; 
    } 
 
 
    //town 
    d1[0] = 0; //начальная вершина 
 
    for(int i=0; i<n; i++){ 
 
        int v = -1; //текущая вершина 
 
        for(int j = 0; j<n; j++){ // поиск минимального 
            if(!u1[j] && (v == -1 || d1[v] > d1[j])){ 
                v = j; 
            } 
        } 
 
        // cout << v+1 << " "; 
        u1[v] = true; 
 
        for(int j=0; j <n; j++){ // update 
            if(!u1[j] && t[v][j] > 0){ 
                if(d1[j] > d1[v] + 1){ 
                    d1[j] = d1[v] + 1; 
                } 
            } 
        } 
    } 
 
    d2[0] = 0; //начальная вершина 
 
    for(int i=0; i<n; i++){ 
 
        int v = -1; //текущая вершина 
 
        for(int j = 0; j<n; j++){ // поиск минимального 
            if(!u2[j] && (v == -1 || d2[v] > d2[j])){ 
                v = j; 
            } 
        } 
 
        // cout << v+1 << " "; 
        u2[v] = true; 
 
        for(int j=0; j <n; j++){ // update 
            if(!u2[j] && r[v][j] > 0){ 
                if(d2[j] > d2[v] + 1){ 
                    d2[j] = d2[v] + 1; 
                } 
            } 
        } 
    } 
 
    int h1 = d1[n]; 
    int h2 = d2[n]; 
    if(h1 < MAX_INT && h2 < MAX_INT) cout << max(h1, h2); 
    else cout << -1; 
 
    return 0; 
}