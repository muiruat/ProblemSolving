#include <iostream>
using namespace std;

void solution(int n, int m) {
    if (m == -1) return;

    if (n == m) cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    for (int i = m; i < n; i++) cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    for (int i = m; i < n; i++) cout << "____";
    if (m == 0) cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    else {
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        for (int i = m; i < n; i++) cout << "____";
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        for (int i = m; i < n; i++) cout << "____";
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    }
    solution(n, m - 1);
    for (int i = m; i < n; i++) cout << "____";
    cout << "��� �亯�Ͽ���.\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    solution(n, n);

    return 0;
}