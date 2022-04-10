#include <iostream>
using namespace std;

int board[128][128];
int ans[2];

bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (board[x][y] != board[i][j])
                return false;

    return true;
}

void solution(int x, int y, int n)
{
    if (check(x, y, n))
    {
        ans[board[x][y]]++;
        return;
    }

    n /= 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            solution(x + n * i, y + n * j, n);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    solution(0, 0, n);

    for (int i = 0; i < 2; i++)
        cout << ans[i] << '\n';

    return 0;
}