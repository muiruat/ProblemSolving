#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;
    stack<int> temp;

    int m;
    cin >> m;

    s.push(m);
    cout << 0 << ' ';

    while (--n)
    {
        cin >> m;

        while (!s.empty() && s.top() < m)
        {
            temp.push(s.top());
            s.pop();
        }

        cout << s.size() << ' ';

        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }

        s.push(m);
    }

    return 0;
}