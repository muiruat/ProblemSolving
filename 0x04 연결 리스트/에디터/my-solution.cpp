#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    list<char> l;
    for (char c : s)
        l.push_back(c);
    list<char>::iterator li = l.end();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        switch (c)
        {
        case 'L':
            if (li != l.begin())
                li--;
            break;
        case 'D':
            if (li != l.end())
                li++;
            break;
        case 'B':
            if (li != l.begin())
            {
                li--;
                li = l.erase(li);
            }
            break;
        case 'P':
            char d;
            cin >> d;
            l.insert(li, d);
            break;
        }
    }

    for (char c : l)
        cout << c;

    return 0;
}