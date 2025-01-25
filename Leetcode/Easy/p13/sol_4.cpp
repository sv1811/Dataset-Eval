#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int len = s.length();
        for(int i =0; i<len-1; i++){
            if(m[s[i]] < m[s[i+1]]) ans -=m[s[i]];
            else ans+=m[s[i]];
        }
        ans+=m[s[len-1]];

        return ans;
        
    }
};