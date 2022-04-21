#include <iostream>
using namespace std;

int n, m, k;
int r, c;
bool board[40][40];
bool sticker[10][10];

bool isStickable(int x, int y)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[x + i][y + j] && sticker[i][j])
                return false;

    return true;
}

void stick(int x, int y)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sticker[i][j])
                board[x + i][y + j] = true;
}

void rotate()
{
    bool temp[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[i][j] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = temp[r - j - 1][i];

    swap(r, c);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;

        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                cin >> sticker[j][k];

        bool isStick = false;
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k <= n - r; k++)
            {
                for (int l = 0; l <= m - c; l++)
                {
                    if (isStickable(k, l))
                    {
                        stick(k, l);
                        isStick = true;
                        break;
                    }
                }

                if (isStick)
                    break;
            }

            if (isStick)
                break;

            rotate();
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j])
                ans++;

    cout << ans;

    return 0;
}