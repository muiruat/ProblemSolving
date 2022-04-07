#include <iostream>
using namespace std;

int soultion(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);
    if (r < half && c < half) return soultion(n - 1, r, c);
    if (r < half && c >= half) return half * half + soultion(n - 1, r, c - half);
    if (r >= half && c < half) return half * half * 2 + soultion(n - 1, r - half, c);
    return half * half * 3 + soultion(n - 1, r - half, c - half);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r, c;
    cin >> n >> r >> c;

    cout << soultion(n, r, c);

    return 0;
}