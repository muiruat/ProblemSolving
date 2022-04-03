#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[500][500];
bool vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    int max = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 1 || vis[i][j])
                continue;

            q.push({i, j});
            vis[i][j] = true;

            int temp = 0;
            while (!q.empty())
            {
                pair<int, int> current = q.front();
                q.pop();
                temp++;

                for (int k = 0; k < 4; k++)
                {
                    int nx = current.first + dx[k];
                    int ny = current.second + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (board[nx][ny] != 1 || vis[nx][ny])
                        continue;

                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }

            cnt++;
            if (max < temp)
                max = temp;
        }
    }

    cout << cnt << '\n'
         << max;

    return 0;
}