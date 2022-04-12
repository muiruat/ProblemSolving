#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
bool check[8];
int ans[8];

void solution(int k, int l)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < l)
            continue;

        if (!check[i] && temp != arr[i])
        {
            ans[k] = arr[i];
            temp = arr[i];
            check[i] = true;
            solution(k + 1, arr[i]);
            check[i] = false;
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
    solution(0, 1);

    return 0;
}