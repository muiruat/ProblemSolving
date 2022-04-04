#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int dx[3] = {-1, 1, 2};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    fill(dist, dist + 100001, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nx;
            if (i == 2) nx = cur * dx[i];
            else nx = cur + dx[i];

            if (nx < 0 || nx >= 100001) continue;
            if (dist[nx] > -1) continue;

            q.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }

    cout << dist[k];

    return 0;
}