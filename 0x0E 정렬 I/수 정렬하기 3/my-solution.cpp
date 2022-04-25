#include <iostream>
using namespace std;

int n;
int arr[10001];

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        arr[m]++;
    }

    for (int i = 1; i < 10001; i++)
        while (arr[i])
        {
            cout << i << '\n';
            arr[i]--;
        }

    return 0;
}