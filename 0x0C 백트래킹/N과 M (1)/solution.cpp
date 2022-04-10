#include <iostream>
using namespace std;

int arr[8];
bool isUsed[9];

void solution(int n, int m, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            arr[k] = i;
            isUsed[i] = true;
            solution(n, m, k + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    solution(n, m, 0);

    return 0;
}