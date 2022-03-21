#include <iostream>
using namespace std;

int a[11];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int b = 0;
    while (n > 0)
    {
        int c = n % 10;
        if (a[c] == 0)
        {
            b++;
            for (int i = 0; i < 10; i++)
            {
                if (i == 6 || i == 9)
                {
                    a[6]++;
                    a[9]++;
                }
                else
                    a[i]++;
            }
        }
        if (c == 6 || c == 9)
        {
            a[6]--;
            a[9]--;
        }
        else
            a[c]--;
        n /= 10;
    }

    cout << b;

    return 0;
}