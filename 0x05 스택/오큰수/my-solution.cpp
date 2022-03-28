#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<int> s1;
    stack<int> s2;
    stack<int> ans;

    while (n--) {
        int m;
        cin >> m;
        s1.push(m);
    }

    while (!s1.empty()) {
        while (!s2.empty() && s1.top() < s2.top()) s2.pop();
        if (s2.empty()) ans.push(-1);
        else ans.push(s2.top());
        s2.push(s1.top());
        s1.pop();
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}