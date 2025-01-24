// Variant 1: Using a Stack
#include <vector>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    for (const string& token : tokens) {
        if (isdigit(token.back())) {
            stack.push(stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") stack.push(a / b);
        }
    }
    return stack.top();
}
