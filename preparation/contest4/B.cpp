/*
Problem B. KH2O - potassium hydroxide???
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
One minion is learning chemistry but its going to be so hard. One day when he was doing an experiment
with potassium and oxygen, he accidentally blew up the flask. Now this time he wants to be careful with
the elements. It has an adjacency matrix where it is written which element can be added with which,
and which cannot be added. The teacher gave him q different requests where each request has 3 chemical
elements, it is necessary to say whether it is possible to add these 3 elements so that the flask does not
explode.
Input
The first line contains two integers n, q (1 <= n <= 1000, 1 <= q <= 100000) — the number of elements
and number of queries
The next n lines contains n integers a[i][j], that means element i can be added to element j if a[i][j] = 1
and if a[i][j] = 0 they cannot be added a[i][i] is equal 1 always
Output
Print "YES"if we can add 3 elements, otherwise print "NO"
standard input standard output
4 4
1 1 0 1
1 1 1 1
0 1 1 0
1 1 0 1
1 2 4
2 3 4
1 2 2
3 3 4
YES
NO
YES
NO
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
int main(){
    int n,q,x,y,z;
    cin >> n >> q;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    
    while(q--){
        cin >> x >> y >> z;
        if(a[x][y]==1 && a[x][z]==1 && a[y][z]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}