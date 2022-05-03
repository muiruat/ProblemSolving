#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long now = arr[0];
    int cnt = 1;
    long long mxval = arr[0];
    int mxcnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (now < arr[i])
        {
            if (cnt > mxcnt)
            {
                mxval = now;
                mxcnt = cnt;
            }

            now = arr[i];
            cnt = 1;
        }
        else
            cnt++;
    }

    if (cnt > mxcnt)
        mxval = now;

    cout << mxval;

    return 0;
}