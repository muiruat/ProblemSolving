#include <iostream>
using namespace std;

int arr[20];

void reverse(int a, int b)
{
    for (int i = 0; i < (b - a + 1) / 2; i++)
        swap(arr[a + i - 1], arr[b - i - 1]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 20; i++)
        arr[i] = i + 1;

    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        reverse(a, b);
    }

    for (int i = 0; i < 20; i++)
        cout << arr[i] << ' ';

    return 0;
}