//Задача №1427. Матрица
#include <iostream>
#include <vector>
using namespace std;
//done
int main(){
    int n,m,min=1e9,max=-1e9,cnt=0;
    cin >> n >> m;
    int a[n][m];
    int aa[n],bb[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<min){
                min=a[i][j];
            }
            
        }
        aa[i]=min;
        min=1e9;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[j][i]>max){
                max=a[j][i];
                
            }
        }
        bb[i]=max;
        max=-1e9;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(aa[i]==bb[j]) cnt++;
        }
    }
    cout << cnt;

    return 0;
}