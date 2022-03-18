#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool arr[1000001];
    for (int i = 0; i < 1000001; i++)
    {
        arr[i] = false;
    }

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        arr[n] = true;
    }

    for (int i = 0; i < 1000001; i++)
    {
        if (arr[i])
            cout << i << ' ';
    }

    return 0;
}
