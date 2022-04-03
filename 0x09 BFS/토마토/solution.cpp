#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1000][1000];
int day[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                day[i][j] = -1;

            if (board[i][j] == 1)
                q.push({i, j});
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

            if (day[nx][ny] != -1)
                continue;

            q.push({nx, ny});
            day[nx][ny] = day[cur.first][cur.second] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (day[i][j] == -1)
            {
                ans = -1;
                break;
            }

            ans = max(day[i][j], ans);
        }

        if (ans == -1)
            break;
    }

    cout << ans;

    return 0;
}