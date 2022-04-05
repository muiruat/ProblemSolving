#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[100][100][100];
int dist[100][100][100];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h;

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> board[j][k][i];

                if (board[j][k][i] == 0)
                    dist[j][k][i] = -1;

                if (board[j][k][i] == 1)
                    q.push({{j, k}, i});
            }

    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            int nz = cur.second + dz[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;

            if (board[nx][ny][nz] == -1 || dist[nx][ny][nz] > -1)
                continue;

            q.push({{nx, ny}, nz});
            dist[nx][ny][nz] = dist[cur.first.first][cur.first.second][cur.second] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                if (dist[j][k][i] == -1)
                {
                    cout << -1;
                    return 0;
                }

                ans = max(dist[j][k][i], ans);
            }

    cout << ans;

    return 0;
}