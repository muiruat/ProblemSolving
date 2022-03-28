#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        stack<pair<int, int>> s;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;

            int idx = i;
            while (!s.empty() && s.top().second >= m)
            {
                ans = max(ans, 1LL * (i - s.top().first) * s.top().second);
                idx = s.top().first;
                s.pop();
            }

            s.push({idx, m});
        }

        while (!s.empty())
        {
            ans = max(ans, 1LL * (n - s.top().first) * s.top().second);
            s.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}