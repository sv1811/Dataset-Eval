// Variant 4: Count Match Approach
#include <string>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    vector<int> target(128, 0), current(128, 0);
    for (char c : t) target[c]++;
    
    int matchCount = 0, minStart = 0, minLen = INT_MAX;
    int start = 0;
    
    for (int end = 0; end < s.length(); end++) {
        current[s[end]]++;
        if (current[s[end]] <= target[s[end]]) matchCount++;
        
        if (matchCount >= t.length()) {
            while (start <= end && current[s[start]] > target[s[start]]) {
                current[s[start]]--;
                start++;
            }
            
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
