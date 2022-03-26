#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    stack<int> s;
    while (k--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            s.pop();
        }
        else
        {
            s.push(n);
        }
    }

    int ans = 0;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout << ans;

    return 0;
}