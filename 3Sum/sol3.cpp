// **Variant 3: Hashing Approach**
vector<vector<int>> threeSumHashing(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 
        unordered_set<int> seen;
        for (int j = i + 1; j < nums.size(); ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement)) {
                result.push_back({nums[i], nums[j], complement});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j; 
            }
            seen.insert(nums[j]);
        }
    }

    return result;
}