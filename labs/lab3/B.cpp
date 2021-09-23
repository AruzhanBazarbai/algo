// Задача №227. Максимальный элемент массива
#include <iostream>
using namespace std;
// done
int main(){
    int n,x=-1e9;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>x){
            x=a[i];
        }
    }
    cout << x;
    return 0;
}