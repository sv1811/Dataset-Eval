class Solution {
public:
    int myAtoi(string s) {
        bool negative=false;
        long long ans=0;
        int i=0;
        while(i<s.length()&&s[i]==' ') i++;
        if(s[i]=='-') {negative=true; i++;}
        else if(s[i]=='+') i++;
        while(i<s.length()&&s[i]>='0'&&s[i]<='9'){
            ans*=10;
            ans+=(long long)s[i]-'0';
            i++;            
        }
        if(negative) ans= -1*ans;
        if(ans>(long long)INT_MAX) return INT_MAX;
        else if(ans<(long long)INT_MIN) return INT_MIN;        
        return ans; 
    }
};