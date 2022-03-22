#include <iostream>
using namespace std;

int r[2][6]; // 성별, 반별 학생 수를 저장하는 배열

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 학생 수 저장
    for (int i = 0; i < n; i++)
    {
        int s, y;
        cin >> s >> y;
        r[s][y - 1]++;
    }

    // 필요한 방의 개수 계산
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            // 배정에 필요한 만큼 방의 개수 추가
            ans += r[i][j] / k;
            // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
            if (r[i][j] % k)
                ans++;
        }
    }

    cout << ans;

    return 0;
}