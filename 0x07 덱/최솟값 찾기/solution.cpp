#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> d;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        while (!d.empty() && d.back().second >= m)
            d.pop_back();

        d.push_back({i, m});

        if (i - d.front().first >= l)
            d.pop_front();

        cout << d.front().second << ' ';
    }

    return 0;
}