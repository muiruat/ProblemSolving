#include <iostream>
using namespace std;

int d[10];

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= 10; i++)
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];

    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}