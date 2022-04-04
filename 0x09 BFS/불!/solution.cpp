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

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }

    for (int i = 0; i < r; i++)
        cin >> board[i];

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] == 'F')
            {
                q1.push({i, j});
                dist1[i][j] = 0;
            }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] == 'J')
            {
                q2.push({i, j});
                dist2[i][j] = 0;
            }

    while (!q1.empty())
    {
        pair<int, int> cur = q1.front();
        q1.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;

            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            q1.push({nx, ny});
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
        }
    }

    while (!q2.empty())
    {
        pair<int, int> cur = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }

            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1)
                continue;

            q2.push({nx, ny});
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}