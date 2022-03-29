#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX * 2 + 1];
int head = MX, tail = MX;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push_front") {
            int m;
            cin >> m;
            dat[--head] = m;
        } else if (s == "push_back") {
            int m;
            cin >> m;
            dat[tail++] = m;
        } else if (s == "pop_front") {
            if (tail == head) cout << -1 << '\n';
            else cout << dat[head++] << '\n';
        } else if (s == "pop_back") {
            if (tail == head) cout << -1 << '\n';
            else {
                cout << dat[tail - 1] << '\n';
                tail--;
            }
        } else if (s == "size") {
            cout << tail - head << '\n';
        } else if (s == "empty") {
            cout << (tail == head) << '\n';
        } else if (s == "front") {
            if (tail == head) cout << -1 << '\n';
            else cout << dat[head] << '\n';
        } else if (s == "back") {
            if (tail == head) cout << -1 << '\n';
            else cout << dat[tail - 1] << '\n';
        }
    }

    return 0;
}