#include <iostream>
using namespace std;

int board[64][64];

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
        cout << board[x][y];
        return;
    }

    cout << '(';

    n /= 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            solution(x + n * i, y + n * j, n);

    cout << ')';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int j = 0;
        for (char c : s)
        {
            board[i][j] = c - '0';
            j++;
        }
    }

    solution(0, 0, n);

    return 0;
}