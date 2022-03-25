#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        string L;
        cin >> L;

        list<char> l;
        list<char>::iterator it = l.end();

        for (char c : L)
        {
            switch (c)
            {
            case '-':
                if (it != l.begin())
                {
                    it--;
                    it = l.erase(it);
                }
                break;
            case '<':
                if (it != l.begin())
                    it--;
                break;
            case '>':
                if (it != l.end())
                    it++;
                break;
            default:
                l.insert(it, c);
                break;
            }
        }

        for (char c : l)
            cout << c;
        cout << '\n';
    }

    return 0;
}