// /*
// The archaeologists are going to decipher a very mysterious “language”. Now, they know many language
// patterns; each pattern can be treated as a string on English letters (only lower case). As a sub string,
// these patterns may appear more than one times in a large text string (also only lower case English
// letters).
// What matters most is that which patterns are the dominating patterns. Dominating pattern is the
// pattern whose appearing times is not less than other patterns.
// It is your job to find the dominating pattern(s) and their appearing times.
// Input
// The entire input contains multi cases. The first line of each case is an integer, which is the number of
// patterns N, 1 ≤ N ≤ 150. Each of the following N lines contains one pattern, whose length is in range
// [1, 70]. The rest of the case is one line contains a large string as the text to lookup, whose length is up
// to 106
// .
// At the end of the input file, number ‘0’ indicates the end of input file.
// Output
// For each of the input cases, output the appearing times of the dominating pattern(s). If there are more
// than one dominating pattern, output them in separate lines; and keep their input order to the output
// Sample Input
// 2
// aba
// bab
// ababababac
// 6
// beta
// alpha
// haha
// delta
// dede
// tata
// dedeltalphahahahototatalpha
// 0
// Sample Output
// 4
// aba
// 2
// alpha
// haha
// */
#include <iostream>
#include <vector>
using namespace std;
// done
int main(){
    int n;
    string s;
    long long p_pow[1000005];
    vector<long long> hashes;
    vector<pair<pair<long long,string>,int> > hash;
    p_pow[0]=1;
    for(int i=1;i<1000005;i++){
        p_pow[i]=p_pow[i-1]*31;
    }
    while(1){
        cin >> n;
        if(n==0) break;
        while(n--){
            cin >> s;
            long long h=0;
            for(int i=0;i<s.size();i++){
                h+=(s[i]-'a'+1)*p_pow[i];
            }
            hash.push_back(make_pair(make_pair(h,s),0));
            
        }
        cin >> s;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            hashes.push_back((s[i]-'a'+1)*p_pow[i]);
            if(i) hashes[i]+=hashes[i-1];
            
            for(int j=0;j<hash.size();j++){
                int t=hash[j].first.second.size();
                if(t<=i+1){
                    long long h1=hashes[i];
                    if(t<=i){
                        h1-=hashes[i-t];
                    }

                    if(hash[j].first.first * p_pow[i-t+1]==h1){
                        hash[j].second++;
                        if(hash[j].second>maxi){
                            maxi=hash[j].second;
                        }
                    }

                }else{
                    continue;
                }
            }
            
        }
        cout << maxi << endl;
        for(int i=0;i<hash.size();i++){
            if(hash[i].second==maxi) cout << hash[i].first.second << endl;
        }
        hash.clear();
        hashes.clear();

    }

    return 0;

}