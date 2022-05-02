#include <iostream>
#include <algorithm>
using namespace std;

string arr[50];

bool cmp(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();

    int aSum = 0;
    for (char c : a)
        if (c >= '0' && c <= '9')
            aSum += c - '0';

    int bSum = 0;
    for (char c : b)
        if (c >= '0' && c <= '9')
            bSum += c - '0';

    if (aSum != bSum)
        return aSum < bSum;

    return a < b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}