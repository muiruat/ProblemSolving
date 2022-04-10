#include <iostream>
using namespace std;

int n;

void print(const char *str, int stk)
{
    for (int i = 0; i < stk; i++)
        cout << "____";
    cout << str;
}

void solution(int stk)
{
    if (stk == n)
    {
        print("\"����Լ��� ������?\"\n", stk);
        print("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", stk);
        print("��� �亯�Ͽ���.\n", stk);
        return;
    }

    if (stk == 0)
        print("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n", stk);

    print("\"����Լ��� ������?\"\n", stk);
    print("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", stk);
    print("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", stk);
    print("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", stk);

    solution(stk + 1);

    print("��� �亯�Ͽ���.\n", stk);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    solution(0);

    return 0;
}