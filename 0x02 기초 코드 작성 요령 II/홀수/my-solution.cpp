#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0, min = 100, num;
    for (int i = 0; i < 7; i++)
    {
        cin >> num;
        if (num % 2 == 0)
            continue;
        sum += num;
        if (num < min)
            min = num;
    }

    if (sum == 0)
    {
        cout << -1;
        return 0;
    }

    cout << sum << '\n'
         << min;

    return 0;
}