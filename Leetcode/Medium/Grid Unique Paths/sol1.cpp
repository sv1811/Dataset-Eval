// **Variant 1: Recursive Approach (Brute Force)**
int uniquePathsRecursive(int m, int n) {
    if (m == 1 || n == 1) return 1;
    return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1);
}