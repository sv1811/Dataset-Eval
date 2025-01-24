// Variant 2: Using Unordered Map
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> needed, window;
    for (char c : t) needed[c]++;
    
    int required = needed.size(), formed = 0;
    int start = 0, minLen = INT_MAX, minStart = 0;
    
    for (int end = 0; end < s.length(); end++) {
        char c = s[end];
        window[c]++;
        
        if (needed.count(c) && window[c] == needed[c]) formed++;
        
        while (formed == required) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }
            
            char leftChar = s[start++];
            window[leftChar]--;
            
            if (needed.count(leftChar) && window[leftChar] < needed[leftChar]) formed--;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
