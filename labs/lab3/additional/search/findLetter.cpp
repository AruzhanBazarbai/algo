// 744. Find Smallest Letter Greater Than Target
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        long long l=0,r=letters.size()-1,ind=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(letters[mid]<=target){
                ind=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(ind==-1) return letters[0];
        else if(letters[ind]==target && ind!=letters.size()-1) return letters[ind+1];
        else if(letters[ind]==target && ind==letters.size()-1) return letters[0];
        else if(letters[ind]!=target && ind==letters.size()-1) return letters[0];
        else if(letters[ind]!=target && ind!=letters.size()-1) return letters[ind+1];
        else return '0';

    }
};