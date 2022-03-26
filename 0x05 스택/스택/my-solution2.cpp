#include <iostream>
using namespace std;

int dat[10000];
int pos = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int n;
            cin >> n;
            dat[pos++] = n;
        }
        else if (s == "pop")
        {
            if (pos == 0)
                cout << -1 << '\n';
            else
                cout << dat[--pos] << '\n';
        }
        else if (s == "size")
        {
            cout << pos << '\n';
        }
        else if (s == "empty")
        {
            if (pos == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (s == "top")
        {
            if (pos == 0)
                cout << -1 << '\n';
            else
                cout << dat[pos - 1] << '\n';
        }
    }

    return 0;
}