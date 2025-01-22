class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int a[2501];
        int rs = 1;
        for(int i = 0; i < nums.size(); i++){
            a[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                a[i] = max(a[i], a[j] + 1);
            }
            rs = max(rs, a[i]);
        }
        return rs;
    }
};