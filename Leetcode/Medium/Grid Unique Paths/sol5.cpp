// **Variant 5: Combinatorics**
int uniquePathsCombinatorics(int m, int n) {
    int N = m + n - 2; // Total moves
    int r = min(m - 1, n - 1); // Choose smaller of down or right moves
    long long result = 1;

    for (int i = 1; i <= r; ++i) {
        result = result * (N - r + i) / i;
    }

    return result;
}
