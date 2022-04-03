#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[100][100];
int vis[100][100];
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
        string s;
        cin >> s;

        int j = 0;
        for (char c : s)
            board[i][j++] = c - '0';
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;

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

            if (vis[nx][ny] != 0 || board[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    cout << vis[n - 1][m - 1];

    return 0;
}