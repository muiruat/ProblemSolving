#include <iostream>
using namespace std;

int a[201];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b + 100]++;
    }

    int v;
    cin >> v;
    cout << a[v + 100];

    return 0;
}