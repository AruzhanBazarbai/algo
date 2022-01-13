// floyd
#include <iostream>

using namespace std;
int g[100][100];
int c[100][100];

int main() {
    int n, m, x, y, l;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            g[i][j] = 1e7;
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--;
        y--;
        g[x][y] = l;
        g[y][x] = l;
    }

    for (int k = 0; k < n; k++) //O(n^3)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                    c[i][j] = k; // c[i][k] c[k][j]
                }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}
