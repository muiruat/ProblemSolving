#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int y = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        y += t / 30 * 10 + 10;
        m += t / 60 * 15 + 15;
    }

    if (y < m)
        cout << "Y " << y;
    if (y > m)
        cout << "M " << m;
    if (y == m)
        cout << "Y M " << y;

    return 0;
}