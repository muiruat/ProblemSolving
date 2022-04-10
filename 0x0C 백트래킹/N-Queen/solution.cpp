#include <iostream>
using namespace std;

int n;
int ans;

bool isUsed1[15];
bool isUsed2[30];
bool isUsed3[30];

void solution(int cur) {
    if (n == cur) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isUsed1[i] || isUsed2[i + cur] || isUsed3[cur - i + n - 1]) continue;

        isUsed1[i] = true;
        isUsed2[i + cur] = true;
        isUsed3[cur - i + n - 1] = true;

        solution(cur + 1);

        isUsed1[i] = false;
        isUsed2[i + cur] = false;
        isUsed3[cur - i + n - 1] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    solution(0);
    cout << ans;

    return 0;
}