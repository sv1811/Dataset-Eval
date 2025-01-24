// Variant 4: Using a Stack with Lambda Functions
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>
#include <functional>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    unordered_map<string, function<int(int, int)>> operations = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}
    };

    for (const string& token : tokens) {
        if (isdigit(token.back())) {
            stack.push(stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(operations[token](a, b));
        }
    }
    return stack.top();
}
