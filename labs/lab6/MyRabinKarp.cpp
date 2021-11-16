// /*187. Repeated DNA Sequences
// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that 
// occur more than once in a DNA molecule. You may return the answer in any order.
// */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int x=10,p=5;
        vector<string> str,res; // str-substrings res-substrings that occurs more than one in string
        vector<pair<pair<long long,int>,int> > cnt; //pair<pair<hash,index in string>,counter>
        vector<pair<long long,int> > hashes; //pair<hash,index in string>
        vector<long long> p_pow;
        p_pow.push_back(1);
        for(int i=1;i<x;i++){
            p_pow.push_back(p_pow[i-1]*p);
        }
        if(s.size()<=x) return res;
        for(int i=0;i<s.length()-x+1;i++){
            str.push_back(s.substr(i,x));
            long long hash=0;
            for(int j=0;j<x;j++){
                hash+=(str[i][j]-'a'+1)*p_pow[j];
            }
            hashes.push_back(make_pair(hash,i));
        }
        sort(hashes.begin(),hashes.end());
        for(int i=0;i<hashes.size();i++){
            if(cnt.empty() || hashes[i].first!=cnt[cnt.size()-1].first.first){
                cnt.push_back(make_pair(make_pair(hashes[i].first,hashes[i].second),1));
                
            }else{
                cnt[cnt.size()-1].second++;
            }
        }
        for(int i=0;i<cnt.size();i++){
            if(cnt[i].second>1){
                res.push_back(str[cnt[i].first.second]);
            }
        }
        return res;
    }
};