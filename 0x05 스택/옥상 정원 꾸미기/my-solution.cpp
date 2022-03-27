#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<int> s;
    s.push(1000000001);
    
    long long ans = 0;
    while (n--) {
        int m;
        cin >> m;

        while (s.top() <= m) {
            s.pop();
        }

        ans += s.size() - 1;

        s.push(m);
    }

    cout << ans;

    return 0;
}