//441. Arranging Coins
#include <iostream>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        long long sum=0,i=1,cnt=-1;
        while(sum<=n){
            cnt++;
            sum+=i;
            i++;
        }
        return cnt;
    }
};