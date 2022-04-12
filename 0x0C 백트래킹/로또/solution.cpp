#include <iostream>
using namespace std;

int k;
int arr[13];
bool check[13];
int ans[6];

void solution(int index) {
    if (index == 6) {
        bool flag = true;
        int before = 0;
        for (int i = 0; i < 6; i++) {
            if (before > ans[i]) {
                flag = false;
                break;
            }
            
            before = ans[i];
        }

        if (flag) {
            for (int i = 0; i < 6; i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }

        return;
    }

    for (int i = 0; i < k; i++) {
        if (!check[i]) {
            ans[index] = arr[i];
            check[i] = true;
            solution(index + 1);
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> k;

        if (k == 0)
            break;

        for (int i = 0; i < k; i++)
            cin >> arr[i];

        solution(0);
        cout << '\n';

        fill(arr, arr + k, 0);
        fill(check, check + k, false);
        fill(ans, ans + 6, 0);
    }

    return 0;
}