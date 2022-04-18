#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
int board1[8][8];
int board2[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}

void ups(int x, int y, int dir)
{
    dir %= 4;

    while (true)
    {
        x += dx[dir];
        y += dy[dir];

        if (oob(x, y) || board2[x][y] == 6)
            return;

        if (board2[x][y] != 0)
            continue;

        board2[x][y] = 7;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> cctv;

    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j];

            if (board1[i][j] > 0 && board1[i][j] < 6)
                cctv.push_back({i, j});

            if (board1[i][j] == 0)
                ans++;
        }

    for (int tmp = 0; tmp < 1 << (cctv.size() * 2); tmp++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];

        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int x = cctv[i].first;
            int y = cctv[i].second;
            int dir = brute % 4;

            brute /= 4;

            if (board1[x][y] == 1)
            {
                ups(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                ups(x, y, dir);
                ups(x, y, dir + 2);
            }
            else if (board1[x][y] == 3)
            {
                ups(x, y, dir);
                ups(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            {
                ups(x, y, dir);
                ups(x, y, dir + 1);
                ups(x, y, dir + 2);
            }
            else if (board1[x][y] == 5)
            {
                ups(x, y, dir);
                ups(x, y, dir + 1);
                ups(x, y, dir + 2);
                ups(x, y, dir + 3);
            }
        }

        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board2[i][j] == 0)
                    val++;

        ans = min(ans, val);
    }

    cout << ans;

    return 0;
}