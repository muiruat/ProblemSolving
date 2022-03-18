#include <iostream>
using namespace std;

char check(int a[])
{
    int b = 0, c = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == 0)
            b++;
        else
            c++;
    }

    if (b == 1 && c == 3)
        return 'A';
    else if (b == 2 && c == 2)
        return 'B';
    else if (b == 3 && c == 1)
        return 'C';
    else if (b == 4 && c == 0)
        return 'D';
    else
        return 'E';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << check(a[i]) << '\n';
    }

    return 0;
}