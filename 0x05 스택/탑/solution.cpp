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
    s.push({0, 100000001}); // 수평 위치, 높이

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;

        while (s.top().second < m)
            s.pop();
        cout << s.top().first << ' ';
        s.push({i, m});
    }

    return 0;
}