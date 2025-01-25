#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        int stored = romanMap[s[s.length()-1]];
        int main = romanMap[s[s.length()-1]];

        for(int i = s.length()-2; i>=0; i--){
            int current = romanMap[s[i]];
            if (main > current) stored -= current;
            else if (main == current) stored += current;
            else if (main < current){
                ans += stored;
                main = current;
                stored = current;
            }
            //cout<< "main: "<<main<< " stored: "<< stored << " ans: " <<ans<<endl;
        }

        return stored + ans ;
    }
};