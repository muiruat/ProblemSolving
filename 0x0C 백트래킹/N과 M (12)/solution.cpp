#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void solution(int k, int start)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = start; i < n; i++)
    {
        if (temp != arr[i])
        {
            ans[k] = arr[i];
            temp = arr[i];
            solution(k + 1, i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    solution(0, 0);

    return 0;
}