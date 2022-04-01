#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int sum = 0; // 더해질 값
    int num = 1; // 곱해질 값

    bool check = true;
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stack.push('(');
            num *= 2;
        }
        else if (s[i] == '[')
        {
            stack.push('[');
            num *= 3;
        }
        else if (s[i] == ')')
        {
            if (stack.empty())
            {
                check = false;
                break;
            }

            if (stack.top() != '(')
            {
                check = false;
                break;
            }

            if (s[i - 1] == '(')
                sum += num;

            stack.pop();
            num /= 2;
        }
        else if (s[i] == ']')
        {
            if (stack.empty())
            {
                check = false;
                break;
            }

            if (stack.top() != '[')
            {
                check = false;
                break;
            }

            if (s[i - 1] == '[')
                sum += num;

            stack.pop();
            num /= 3;
        }
    }

    if (!stack.empty())
        check = false;

    if (check)
        cout << sum;
    else
        cout << 0;

    return 0;
}