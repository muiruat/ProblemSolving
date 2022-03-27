#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool check = true;
    int cnt = 1;
    stack<int> s;
    queue<char> ans;
    while (n--)
    {
        int m;
        cin >> m;

        while (cnt <= m)
        {
            s.push(cnt++);
            ans.push('+');
        }

        if (s.empty())
        {
            check = false;
            break;
        }
        else
        {
            if (s.top() != m)
            {
                check = false;
                break;
            }

            s.pop();
            ans.push('-');
        }
    }

    if (check)
    {
        while (!ans.empty())
        {
            cout << ans.front() << '\n';
            ans.pop();
        }
    }
    else
        cout << "NO";

    return 0;
}