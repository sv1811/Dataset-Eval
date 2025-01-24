// Variant 5: Filtered Character Approach
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> dict;
    for (char c : t) dict[c]++;
    
    vector<pair<int, char>> filtered;
    for (int i = 0; i < s.length(); i++) {
        if (dict.count(s[i])) filtered.emplace_back(i, s[i]);
    }
    
    int required = t.length();
    unordered_map<char, int> window;
    int formed = 0, start = 0;
    int minLen = INT_MAX, resultStart = 0, resultLen = 0;
    
    for (int end = 0; end < filtered.size(); end++) {
        char c = filtered[end].second;
        window[c]++;
        if (window[c] <= dict[c]) formed++;
        
        while (formed == required) {
            int currLen = filtered[end].first - filtered[start].first + 1;
            if (currLen < minLen) {
                minLen = currLen;
                resultStart = filtered[start].first;
                resultLen = currLen;
            }
            
            char startChar = filtered[start].second;
            window[startChar]--;
            if (window[startChar] < dict[startChar]) formed--;
            start++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(resultStart, resultLen);
}
