#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    deque<int> d;
    int min = 1000000001;
    for (int i = 0; i < l; i++)
    {
        int m;
        cin >> m;
        d.push_back(m);
        if (min > m)
            min = m;
        cout << min << ' ';
    }

    for (int i = l; i < n; i++)
    {
        int m;
        cin >> m;
        d.push_back(m);
        if (min > m)
            min = m;
        int temp = d.front();
        d.pop_front();
        if (min == temp)
            min = *min_element(d.begin(), d.end());
        cout << min << ' ';
    }

    return 0;
}