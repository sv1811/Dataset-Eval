#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(int low,int high,string &v){
        while(low<high){
            if(v[low]!=v[high])return false;
            low++,high--;
        }
        return true;
    }
    string solve(int low,int high,string &s,vector<vector<int>>&dp){
        if(low>high)return "";
        if(low==high){
            string ans="";
            ans+=s[low];
            return ans;
        }
        if(dp[low][high]!=-1){
            return dp[low][high]==1? s.substr(low,high-low+1) :"";
        }
        if(isPalindrome(low,high,s)){
            dp[low][high]=1;
            return s.substr(low,high-low+1);
        }
                string a1=solve(low,high-1,s,dp);
                string b1=solve(low+1,high,s,dp);
                dp[low][high]=0;
                if(a1.size()>b1.size())return a1;
                return b1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return solve(0,n-1,s,dp);
    }
};