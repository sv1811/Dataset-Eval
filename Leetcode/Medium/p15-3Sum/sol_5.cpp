class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            int target= -nums[i];
            int low= i+1;
            int high=nums.size()-1;

            while(low<high){
                int sum=nums[low]+nums[high];
                if(sum<target) low++;
                else if(sum>target) high--;
                else{
                    vector<int> temp={nums[i], nums[low], nums[high]};
                    res.push_back(temp);
                    
                    //for dup
                    while(low<high && nums[low]==temp[1]) low++;
                    while(low<high && nums[high]==temp[2]) high--;
                }
            }

            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }

        return res;
    }
};