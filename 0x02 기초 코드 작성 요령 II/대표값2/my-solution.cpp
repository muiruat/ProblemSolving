#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    int b = 0, c;
    sort(a, a + 5);
    for (int i = 0; i < 5; i++)
        b += a[i];
    b /= 5;
    c = a[2];

    cout << b << '\n'
         << c;

    return 0;
}