#include <iostream>
#include <queue>
#include <utility>
using namespace std;

string board[100];
bool vis1[100][100];
bool vis2[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queue<pair<int, int>> q;
            if (!vis1[i][j])
            {
                q.push({i, j});
                vis1[i][j] = true;
                ans1++;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (vis1[nx][ny] || board[cur.first][cur.second] != board[nx][ny])
                        continue;

                    q.push({nx, ny});
                    vis1[nx][ny] = true;
                }
            }
        }
    }

    int ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queue<pair<int, int>> q;
            if (!vis2[i][j])
            {
                q.push({i, j});
                vis2[i][j] = true;
                ans2++;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (vis2[nx][ny])
                        continue;

                    if (board[nx][ny] == 'R' || board[nx][ny] == 'G')
                    {
                        if (board[cur.first][cur.second] == 'B')
                            continue;
                    }
                    else
                    {
                        if (board[cur.first][cur.second] != 'B')
                            continue;
                    }

                    q.push({nx, ny});
                    vis2[nx][ny] = true;
                }
            }
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}