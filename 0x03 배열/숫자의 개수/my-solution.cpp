#include <iostream>
using namespace std;

int arr[10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    int d = a * b * c;
    while (d > 0)
    {
        arr[d % 10]++;
        d /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << '\n';

    return 0;
}