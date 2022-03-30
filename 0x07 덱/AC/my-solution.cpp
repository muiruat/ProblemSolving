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
        bool reverse = false;
        for (char c : p)
        {
            if (c == 'R')
            {
                reverse = !reverse;
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
                    if (reverse) {
                        d.pop_back();
                    } else {
                        d.pop_front();
                    }
                }
            }
        }

        if (check)
        {
            cout << '[';
            while (!d.empty() && d.size() != 1)
            {
                if (reverse) {
                    cout << d.back() << ',';
                    d.pop_back();
                } else {
                    cout << d.front() << ',';
                    d.pop_front();
                }
            }
            if (d.empty())
                cout << "]\n";
            else {
                if (reverse)
                    cout << d.back() << "]\n";
                else
                    cout << d.front() << "]\n";
            }
        }
        else
            cout << "error\n";
    }

    return 0;
}