// Variant 3: Using Fixed Size Array with Character Index Map
#include <string>
#include <array>
using namespace std;

string minWindow(string s, string t) {
    array<int, 52> needed{}, window{};
    int getIndex(char c) { return c >= 'a' ? c - 'a' + 26 : c - 'A'; }
    
    for (char c : t) needed[getIndex(c)]++;
    
    int required = 0;
    for (int count : needed) if (count > 0) required++;
    
    int formed = 0, start = 0, minLen = INT_MAX, minStart = 0;
    
    for (int end = 0; end < s.length(); end++) {
        int idx = getIndex(s[end]);
        window[idx]++;
        
        if (needed[idx] > 0 && window[idx] == needed[idx]) formed++;
        
        while (formed == required) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }
            
            idx = getIndex(s[start]);
            window[idx]--;
            
            if (needed[idx] > 0 && window[idx] < needed[idx]) formed--;
            start++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
