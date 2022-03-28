#include <iostream>
using namespace std;

const int MX = 2000000;
int dat[MX];
int head = 0, tail = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int n;
            cin >> n;
            dat[tail++] = n;
        } else if (s == "pop") {
            if (head == tail) cout << -1 << '\n';
            else cout << dat[head++] << '\n';
        } else if (s == "size") {
            cout << tail - head << '\n';
        } else if (s == "empty") {
            if (head == tail) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (s == "front") {
            if (head == tail) cout << -1 << '\n';
            else cout << dat[head] << '\n';
        } else if (s == "back") {
            if (head == tail) cout << -1 << '\n';
            else cout << dat[tail - 1] << '\n';
        }
    }

    return 0;
}