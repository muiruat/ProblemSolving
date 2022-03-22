#include <iostream>
using namespace std;

int r[2][6]; // ����, �ݺ� �л� ���� �����ϴ� �迭

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // �л� �� ����
    for (int i = 0; i < n; i++)
    {
        int s, y;
        cin >> s >> y;
        r[s][y - 1]++;
    }

    // �ʿ��� ���� ���� ���
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            // ������ �ʿ��� ��ŭ ���� ���� �߰�
            ans += r[i][j] / k;
            // �л��� ���� ���, �ϳ��� ���� �� �ʿ��ϹǷ� ���� ���� �߰�
            if (r[i][j] % k)
                ans++;
        }
    }

    cout << ans;

    return 0;
}