#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long c;
    int d;
    if (a > b)
    {
        c = a - b - 1;
        d = 0;
    }
    if (b > a)
    {
        c = b - a - 1;
        d = 1;
    }
    if (a == b)
    {
        c = 0;
        d = 2;
    }
    cout << c << '\n';

    if (d == 0)
    {
        for (long long i = b + 1; i < a; i++)
            cout << i << ' ';
    }
    if (d == 1)
    {
        for (long long i = a + 1; i < b; i++)
            cout << i << ' ';
    }

    return 0;
}