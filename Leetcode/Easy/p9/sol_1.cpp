class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;
        }
        int r = x;
       long long a = 0;
        while(x>0){
       int b = x%10;
      a = a*10+b;
      x = x/10;
        }
        return a == r;
    }
};