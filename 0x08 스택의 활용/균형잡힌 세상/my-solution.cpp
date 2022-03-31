#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    bool check = true;
    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") break;

        check = true;
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[') stack.push(c);
            else if (c == ')') {
                if (stack.empty()) check = false;
                else {
                    if (stack.top() != '(') check = false;
                    else stack.pop();
                }
            } else if (c == ']') {
                if (stack.empty()) check = false;
                else {
                    if (stack.top() != '[') check = false;
                    else stack.pop();
                }
            }
        }

        if (!stack.empty()) check = false;

        if (check) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}