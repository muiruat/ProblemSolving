#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    list<int> l;
    for (int i = 1; i <= n; i++)
        l.push_back(i);

    cout << '<';

    int check = 1;
    list<int>::iterator it = l.begin();
    while (n != 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            it++;
            if (it == l.end())
                it = l.begin();
        }
        cout << *it << ", ";
        it = l.erase(it);
        n--;
        if (it == l.end())
            it = l.begin();
    }

    cout << *it << '>';

    return 0;
}