// Variant 5: Dynamic Programming with Bitmasking
#include <vector>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> dp(1 << numCourses, -1);
    vector<int> prereqs(numCourses, 0);
    
    // Create bitmask of prerequisites for each course
    for (const auto& p : prerequisites) {
        prereqs[p[0]] |= (1 << p[1]);
    }
    
    // Check if state is valid (all required courses are taken)
    auto isValid = [&](int state, int course) {
        return (state & prereqs[course]) == prereqs[course];
    };
    
    // DP function to check if courses can be completed
    function<bool(int)> solve = [&](int state) -> bool {
        if (state == (1 << numCourses) - 1) return true;
        if (dp[state] != -1) return dp[state];
        
        dp[state] = 0;
        for (int course = 0; course < numCourses; course++) {
            if (!(state & (1 << course)) && isValid(state, course)) {
                if (solve(state | (1 << course))) {
                    dp[state] = 1;
                    break;
                }
            }
        }
        return dp[state];
    };
    
    return solve(0);
}
