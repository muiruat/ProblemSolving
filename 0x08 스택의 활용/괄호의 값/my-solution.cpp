#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ans = 0;
    stack<pair<char, int>> stack;
    bool check = true;
    char before = 'n';
    for (char c : s)
    {
        if (c == '(')
        {
            stack.push({c, 0});
            before = '(';
        }
        else if (c == '[')
        {
            stack.push({c, 0});
            before = '[';
        }
        else if (c == ')')
        {
            if (stack.empty())
            {
                check = false;
                break;
            }
            else
            {
                if (stack.top().first != '(')
                {
                    check = false;
                    break;
                }
                else
                {
                    if (before == '(')
                    {
                        stack.pop();

                        if (stack.empty())
                            ans += 2;
                        else
                            stack.top().second += 2;
                    }
                    else
                    {
                        int temp = stack.top().second * 2;
                        stack.pop();

                        if (stack.empty())
                            ans += temp;
                        else
                            stack.top().second += temp;
                    }

                    before = ')';
                }
            }
        }
        else if (c == ']')
        {
            if (stack.empty())
            {
                check = false;
                break;
            }
            else
            {
                if (stack.top().first != '[')
                {
                    check = false;
                    break;
                }
                else
                {
                    if (before == '[')
                    {
                        stack.pop();

                        if (stack.empty())
                            ans += 3;
                        else
                            stack.top().second += 3;
                    }
                    else
                    {
                        int temp = stack.top().second * 3;
                        stack.pop();

                        if (stack.empty())
                            ans += temp;
                        else
                            stack.top().second += temp;
                    }

                    before = ']';
                }
            }
        }
    }

    if (check)
        cout << ans;
    else
        cout << 0;

    return 0;
}