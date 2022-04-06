#include <iostream>
#include <queue>
#include <utility>
using namespace std;

string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        int w, h;
        cin >> w >> h;

        for (int i = 0; i < h; i++)
            cin >> board[i];

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '.')
                {
                    dist1[i][j] = -1;
                    dist2[i][j] = -1;
                }

                if (board[i][j] == '*')
                {
                    q1.push({i, j});
                    dist1[i][j] = 0;
                }

                if (board[i][j] == '@')
                {
                    q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }

        while (!q1.empty())
        {
            pair<int, int> cur = q1.front();
            q1.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                if (board[nx][ny] == '#' || dist1[nx][ny] > -1)
                    continue;

                q1.push({nx, ny});
                dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            }
        }

        bool isPossible = false;
        while (!q2.empty())
        {
            pair<int, int> cur = q2.front();
            q2.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    isPossible = true;
                    cout << dist2[cur.first][cur.second] + 1 << '\n';
                    break;
                }

                if (board[nx][ny] == '#' || dist2[nx][ny] > -1)
                    continue;

                if (dist1[nx][ny] > -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1)
                    continue;

                q2.push({nx, ny});
                dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            }

            if (isPossible)
                break;
        }

        if (!isPossible)
            cout << "IMPOSSIBLE" << '\n';

        for (int i = 0; i < h; i++)
        {
            fill(dist1[i], dist1[i] + w, 0);
            fill(dist2[i], dist2[i] + w, 0);
        }
    }

    return 0;
}