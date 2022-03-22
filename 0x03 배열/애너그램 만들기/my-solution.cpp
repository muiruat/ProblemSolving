#include <iostream>
using namespace std;

int a[26];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    for (char c : s1)
        a[c - 'a']++;
    for (char c : s2)
        a[c - 'a']--;

    int ans = 0;
    for (int n : a)
        ans += abs(n);

    cout << ans;

    return 0;
}