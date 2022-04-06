#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[300][300];
int dist[300][300];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        int l;
        cin >> l;

        for (int i = 0; i < l; i++)
            fill(dist[i], dist[i] + l, -1);

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        queue<pair<int, int>> q;
        q.push({a, b});
        dist[a][b] = 0;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;

                if (dist[nx][ny] > -1)
                    continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }

        cout << dist[c][d] << '\n';

        for (int i = 0; i < l; i++)
            fill(dist[i], dist[i] + l, -1);
    }

    return 0;
}