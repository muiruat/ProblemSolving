#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;

        stack<char> stack;
        for (char c : s)
        {
            if (!stack.empty() && stack.top() == c)
                stack.pop();
            else
                stack.push(c);
        }

        if (stack.empty())
            ans++;
    }

    cout << ans;

    return 0;
}