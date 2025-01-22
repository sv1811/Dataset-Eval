// **Variant 5: Lexicographic (Binary Sorted Subsets)**
vector<vector<int>> subsetsLexicographic(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Ensure lexicographic order

    int n = nums.size();
    int totalSubsets = 1 << n;

    for (int mask = 0; mask < totalSubsets; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}