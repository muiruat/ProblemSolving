#include <iostream>
using namespace std;

int arr[301];
int d[301];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }

    if (n <= 2)
    {
        cout << tot;
        return 0;
    }

    d[1] = arr[1];
    d[2] = arr[2];
    d[3] = arr[3];
    for (int i = 4; i <= n; i++)
        d[i] = min(d[i - 3], d[i - 2]) + arr[i];

    cout << tot - min(d[n - 1], d[n - 2]);

    return 0;
}