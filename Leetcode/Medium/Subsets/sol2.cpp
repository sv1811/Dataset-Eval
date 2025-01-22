// **Variant 2: Iterative Approach**
vector<vector<int>> subsetsIterative(vector<int>& nums) {
    vector<vector<int>> result = { { } };
    for (int num : nums) {
        int n = result.size();
        for (int i = 0; i < n; ++i) {
            vector<int> subset = result[i];
            subset.push_back(num);
            result.push_back(subset);
        }
    }
    return result;
}