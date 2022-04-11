#include <iostream>
using namespace std;

int n, goal, ans;
int arr[20];

void solution(int cur, int sum) {
    if (cur == n) {
        if (sum == goal) ans++;
        return;
    }

    solution(cur + 1, sum);
    solution(cur + 1, sum + arr[cur]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> goal;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    solution(0, 0);

    if (goal == 0) ans--;
    cout << ans;

    return 0;
}