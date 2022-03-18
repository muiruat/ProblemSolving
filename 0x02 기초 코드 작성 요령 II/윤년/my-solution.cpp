#include <iostream>
using namespace std;

int solution(int n)
{
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << solution(n);

    return 0;
}