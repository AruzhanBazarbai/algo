// 374. Guess Number Higher or Lower
#include <iostream>
using namespace std;
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int mid){
    
}
class Solution {
public:
    int guessNumber(int n) {
        int l=0,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)==-1) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};