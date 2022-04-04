#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool board[50][50];
bool vis[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        while (k--) {
            int i, j;
            cin >> i >> j;
            board[i][j] = true;
        }

        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                    ans++;
                }

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] || !board[nx][ny]) continue;

                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        cout << ans << '\n';

        for (int i = 0; i < m; i++) {
            fill(board[i], board[i] + n, false);
            fill(vis[i], vis[i] + n, false);
        }
    }

    return 0;
}