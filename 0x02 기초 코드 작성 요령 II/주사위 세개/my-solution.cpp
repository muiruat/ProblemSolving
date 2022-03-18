#include <iostream>
#include <algorithm>
using namespace std;

int solution(int a, int b, int c)
{
    if (a == b && b == c && a == c)
        return a * 1000 + 10000;
    if (a == b)
        return a * 100 + 1000;
    if (b == c)
        return b * 100 + 1000;
    if (a == c)
        return c * 100 + 1000;
    return max({a, b, c}) * 100;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c);

    return 0;
}