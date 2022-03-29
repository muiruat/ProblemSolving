#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    deque<int> d;
    for (int i = 1; i <= n; i++) d.push_back(i);

    int ans = 0;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;

        int cnt1 = 0;
        while (d.front() != m) {
            d.push_back(d.front());
            d.pop_front();
            cnt1++;
        }

        for (int i = 0; i < cnt1; i++) {
            d.push_front(d.back());
            d.pop_back();
        }

        int cnt2 = 0;
        while (d.front() != m) {
            d.push_front(d.back());
            d.pop_back();
            cnt2++;
        }

        d.pop_front();
        ans += min(cnt1, cnt2);
    }

    cout << ans;

    return 0;
}