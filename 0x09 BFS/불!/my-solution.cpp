#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1000][1000];
int minute[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    queue<pair<bool, pair<int, int>>> q;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        int j = 0;
        for (char c : s) {
            if (c == '#') board[i][j] = -1;
            if (c == '.') board[i][j] = 0;
            if (c == 'J') {
                board[i][j] = 1;
                q.push({true, {i, j}});
            }
            if (c == 'F') {
                board[i][j] = 2;
                q.push({false, {i, j}});
            }

            j++;
        }
    }

    while (!q.empty()) {
        pair<bool, pair<int, int>> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.second.first + dx[i];
            int ny = cur.second.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (cur.first) {
                // 지훈
                if (board[nx][ny] == -1 || board[nx][ny] == 1 || board[nx][ny] == 2) continue;
                if (minute[nx][ny] > 0) continue;

                minute[nx][ny] = minute[cur.second.first][cur.second.second] + 1;
                q.push({true, {nx, ny}});
            } else {
                // 불
                if (board[nx][ny] == -1 || board[nx][ny] == 2) continue;

                board[nx][ny] = 2;
                q.push({false, {nx, ny}});
            }
        }
    }

    bool isPossible = false;
    int ans = 1000001;
    for (int i = 0; i < c; i++) {
        if (board[0][i] == 1) {
            isPossible = true;
            ans = 0;
        }

        if (minute[0][i]) {
            isPossible = true;
            ans = min(minute[0][i], ans);
        }
    }

    for (int i = 0; i < c; i++) {
        if (board[r - 1][i] == 1) {
            isPossible = true;
            ans = 0;
        }

        if (minute[r - 1][i]) {
            isPossible = true;
            ans = min(minute[r - 1][i], ans);
        }
    }

    for (int i = 0; i < r; i++) {
        if (board[i][0] == 1) {
            isPossible = true;
            ans = 0;
        }

        if (minute[i][0]) {
            isPossible = true;
            ans = min(minute[i][0], ans);
        }
    }

    for (int i = 0; i < r; i++) {
        if (board[i][c - 1] == 1) {
            isPossible = true;
            ans = 0;
        }

        if (minute[i][c - 1]) {
            isPossible = true;
            ans = min(minute[i][c - 1], ans);
        }
    }

    if (isPossible) {
        cout << ans + 1;
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}