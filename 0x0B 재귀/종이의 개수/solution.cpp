#include <iostream>
using namespace std;

int board[2187][2187];
int ans[3];

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
        ans[board[x][y] + 1]++;
        return;
    }

    n /= 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
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

    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';

    return 0;
}