#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ans = 0;
    char before = '(';
    stack<bool> stack;
    for (char c : s)
    {
        if (c == '(')
        {
            stack.push(true);
            before = '(';
        }
        else if (c == ')')
        {
            if (before == '(')
            {
                stack.pop();
                ans += stack.size();
            }
            else if (before == ')')
            {
                stack.pop();
                ans++;
            }

            before = ')';
        }
    }

    cout << ans;

    return 0;
}