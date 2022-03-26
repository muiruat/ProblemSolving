#include <iostream>
#include <vector>
using namespace std;

int pre[5001];
int nxt[5001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i == 1 ? n : i - 1;
        nxt[i] = i == n ? 1 : i + 1;
        len++;
    }

    cout << '<';

    int check = 1;
    for (int cur = 1; len != 0; cur = nxt[cur])
    {
        if (check == k)
        {
            nxt[pre[cur]] = nxt[cur];
            pre[nxt[cur]] = pre[cur];
            len--;
            check = 1;
            cout << cur;
            if (len != 0)
                cout << ", ";
            else
                cout << '>';
        }
        else
            check++;
    }

    return 0;
}