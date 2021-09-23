// Задача №228. Номер максимального элемента массива
#include <iostream>
using namespace std;
// done
int main(){
    int n,x=-1e9,ind;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>x){
            ind=i+1;
            x=a[i];
        }
    }
    cout << ind;
    return 0;
}