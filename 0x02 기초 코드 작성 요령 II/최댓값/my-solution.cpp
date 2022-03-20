#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int max = 0, index = 0;
    for (int i = 0; i < 9; i++)
    {
        int n;
        cin >> n;
        if (n > max)
        {
            max = n;
            index = i + 1;
        }
    }

    cout << max << '\n'
         << index;

    return 0;
}