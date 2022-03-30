#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void parse(string &s, deque<int> &d) {
    int current = 0;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == ',') {
            d.push_back(current);
            current = 0;
        } else {
            current = current * 10 + s[i] - '0';
        }
    }

    if (current != 0) {
        d.push_back(current);
    }
}

void printDeque(deque<int> &d) {
    cout << '[';
    for (int i = 0; i < d.size(); i++) {
        cout << d[i];
        if (i != d.size() - 1) cout << ',';
    }
    cout << ']' << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string query;
        cin >> query;

        int n;
        cin >> n;

        string array_string;
        cin >> array_string;

        deque<int> d;
        parse(array_string, d);

        bool isWrong = false;
        bool isReverse = false;
        for (char c : query) {
            if (c == 'R')
                isReverse = !isReverse;
            else if (c == 'D') {
                if (d.empty()) {
                    isWrong = true;
                    break;
                } else {
                    if (isReverse) d.pop_back();
                    else d.pop_front();
                }
            }
        }

        if (isReverse) reverse(d.begin(), d.end());
        if (isWrong)
            cout << "error\n";
        else
            printDeque(d);
    }

    return 0;
}