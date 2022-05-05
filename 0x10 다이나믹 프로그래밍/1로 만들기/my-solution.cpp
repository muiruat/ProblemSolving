#include <iostream>
using namespace std;

int d[1000000];

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int tmp1 = 1000000;
        int tmp2 = 1000000;
        int tmp3 = 1000000;
        if (i % 2 == 0)
            tmp1 = d[i / 2] + 1;

        if (i % 3 == 0)
            tmp2 = d[i / 3] + 1;

        tmp3 = d[i - 1] + 1;

        d[i] = min(min(tmp1, tmp2), tmp3);
    }

    cout << d[n];

    return 0;
}