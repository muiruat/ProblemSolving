#include <iostream>
using namespace std;

int solution(int a, int b, int c) {
    if (b == 0) return 1;
    long long result = a * solution(a, b - 1, c);
    return result % c;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    cout << solution(a, b, c);

    return 0;
}