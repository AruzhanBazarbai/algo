// Задача №226. Линейный поиск - 3
#include <iostream>
#include <queue>
using namespace std;
//done
int main(){
    int n,x;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> x;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout << i+1 << " ";
        }
    }

}