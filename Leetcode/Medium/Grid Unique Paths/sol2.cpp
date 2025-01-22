// **Variant 2: Recursive with Memoization**
int uniquePathsMemoHelper(int m, int n, vector<vector<int>>& memo) {
    if (m == 1 || n == 1) return 1;
    if (memo[m][n] != -1) return memo[m][n];

    memo[m][n] = uniquePathsMemoHelper(m - 1, n, memo) + uniquePathsMemoHelper(m, n - 1, memo);
    return memo[m][n];
}
int uniquePathsMemoization(int m, int n) {
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return uniquePathsMemoHelper(m, n, memo);
}