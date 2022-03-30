#include <iostream>
#include <deque>
#include <algorithm>
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

        int idx = find(d.begin(), d.end(), m) - d.begin();

        while (d.front() != m) {
            if (d.size() - idx > idx) {
                d.push_back(d.front());
                d.pop_front();
            } else {
                d.push_front(d.back());
                d.pop_back();
            }
            ans++;
        }

        d.pop_front();
    }

    cout << ans;

    return 0;
}