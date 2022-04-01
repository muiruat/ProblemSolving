#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        bool check = true;
        stack<bool> stack;
        for (char c : s)
        {
            if (c == '(')
                stack.push(true);
            else if (c == ')')
            {
                if (stack.empty())
                {
                    check = false;
                    break;
                }
                else
                    stack.pop();
            }
        }

        if (!stack.empty())
            check = false;

        if (check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}