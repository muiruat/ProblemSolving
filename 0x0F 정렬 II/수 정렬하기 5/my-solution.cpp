#include <iostream>
using namespace std;

int freq[2000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;
        freq[m + 1000000]++;
    }

    for (int i = 0; i < 2000001; i++)
        for (int j = 0; j < freq[i]; j++)
            cout << i - 1000000 << '\n';

    return 0;
}