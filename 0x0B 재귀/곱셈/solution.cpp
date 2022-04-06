#include <iostream>
using namespace std;

int solution(int a, int b, int c) {
    if (b == 1) return a % c;
    long long val = solution(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return a * val % c;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    cout << solution(a, b, c);

    return 0;
}