#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = a[0], ans_l = 0, ans_r = 0;
    int sum = 0, min_sum = 0, min_pos = -1;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        int cur = abs(sum - min_sum);
        if (cur > abs(ans)) {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }
        if (abs(sum) < abs(min_sum)) {
            min_sum = abs(sum);
            min_pos = r;
        }
    }
    cout << min_sum << " " << sum;
}