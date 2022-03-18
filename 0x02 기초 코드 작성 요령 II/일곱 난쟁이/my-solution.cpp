#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[9], sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + 9);

    int b, c;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - a[i] - a[j] == 100)
            {
                b = i;
                c = j;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (i == b || i == c)
            continue;
        cout << a[i] << '\n';
    }

    return 0;
}