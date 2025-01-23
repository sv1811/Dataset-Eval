class Solution {
public:
    int myAtoi(string s) {
        bool negative=false;
        double ans=0;
        int i=0;
        while(i<s.length()&&s[i]==' ') i++;
        if(s[i]=='-') {negative=true; i++;}
        else if(s[i]=='+') i++;
        while(i<s.length()&&s[i]>='0'&&s[i]<='9'){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i]-'0' > 7)){
                return negative ? INT_MIN : INT_MAX;
            }
            ans*=10;
            ans+=(long long)s[i]-'0';
            i++;            
        }
        if(negative) ans= -1*ans;
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans;   
        return (int)ans; 
    }
};