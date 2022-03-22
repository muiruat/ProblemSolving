#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool isPossible = true;
    for (int i = 0; i < n; i++)
    {
        isPossible = true;

        string a, b;
        cin >> a >> b;

        int check[26] = {};
        for (char c : a)
            check[c - 'a']++;
        for (char c : b)
            check[c - 'a']--;

        for (int n : check)
        {
            if (n != 0)
                isPossible = false;
        }

        if (isPossible)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }

    return 0;
}