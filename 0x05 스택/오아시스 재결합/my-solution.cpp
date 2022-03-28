#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<pair<int, int>> s;

    long long ans = 0;
    while (n--)
    {
        int m;
        cin >> m;

        int cnt = 1;
        while (!s.empty() && s.top().first <= m)
        {
            if (s.top().first == m)
                cnt += s.top().second;
            ans += s.top().second;
            s.pop();
        }

        if (!s.empty())
            ans++;

        s.push({m, cnt});
    }

    cout << ans;

    return 0;
}