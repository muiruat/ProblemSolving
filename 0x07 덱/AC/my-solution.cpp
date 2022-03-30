#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

deque<int> split(string str)
{
    str.erase(0, 1);
    str.erase(str.length() - 1, str.length());

    istringstream iss(str);
    string buffer;

    deque<int> result;

    while (getline(iss, buffer, ','))
    {
        result.push_back(stoi(buffer));
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> d;
        if (n > 0)
        {
            d = split(arr);
        }

        bool check = true;
        for (char c : p)
        {
            if (c == 'R')
            {
                deque<int> temp;
                int m = d.size();
                for (int i = 0; i < m; i++)
                {
                    temp.push_front(d.front());
                    d.pop_front();
                }
                d = temp;
            }
            else if (c == 'D')
            {
                if (d.empty())
                {
                    check = false;
                    break;
                }
                else
                {
                    d.pop_front();
                }
            }
        }

        if (check)
        {
            cout << '[';
            while (!d.empty() && d.size() != 1)
            {
                cout << d.front() << ',';
                d.pop_front();
            }
            cout << d.front() << "]\n";
        }
        else
            cout << "error\n";
    }

    return 0;
}