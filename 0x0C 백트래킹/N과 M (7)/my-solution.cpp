#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[7];
int ans[7];

void solution(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        ans[k] = arr[i];
        solution(k + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    solution(0);

    return 0;
}