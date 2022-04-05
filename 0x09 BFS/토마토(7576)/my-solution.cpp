#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1000][1000];
bool vis[1000][1000];
int day[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (board[nx][ny] == -1)
                continue;

            if (vis[nx][ny])
            {
                day[nx][ny] = min(day[nx][ny], day[cur.first][cur.second] + 1);
                continue;
            }

            q.push({nx, ny});
            vis[nx][ny] = true;
            day[nx][ny] = day[cur.first][cur.second] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 0)
            {
                ans = -1;
                break;
            }

            if (day[i][j] > ans)
                ans = day[i][j];
        }

        if (ans == -1)
            break;
    }

    cout << ans;

    return 0;
}