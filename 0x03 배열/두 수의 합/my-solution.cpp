#include <iostream>
using namespace std;

int occur[2000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[100000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - a[i] > 0 && occur[x - a[i]])
            ans++;
        occur[a[i]] = 1;
    }

    cout << ans;

    return 0;
}