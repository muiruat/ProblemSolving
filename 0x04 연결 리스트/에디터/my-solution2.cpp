#include <iostream>
using namespace std;

const int MAX = 1000005;
char dat[MAX];
int pre[MAX];
int nxt[MAX];
int unused = 1;

void insert(int addr, char value)
{
    dat[unused] = value;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(pre, pre + MAX, -1);
    fill(nxt, nxt + MAX, -1);

    string s;
    cin >> s;

    int cur = 0;
    for (char c : s)
    {
        insert(cur, c);
        cur++;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        switch (c)
        {
        case 'L':
            if (pre[cur] != -1)
                cur = pre[cur];
            break;
        case 'D':
            if (nxt[cur] != -1)
                cur = nxt[cur];
            break;
        case 'B':
            if (pre[cur] != -1)
            {
                erase(cur);
                cur = pre[cur];
            }
            break;
        case 'P':
            char d;
            cin >> d;
            insert(cur, d);
            cur = nxt[cur];
            break;
        }
    }

    traverse();

    return 0;
}