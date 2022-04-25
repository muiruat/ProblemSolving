#include <iostream>
using namespace std;

int n;
int arr[1000000];
int tmp[1000000];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int lIdx = start;
    int rIdx = mid;
    for (int i = start; i < end; i++)
    {
        if (rIdx == end)
            tmp[i] = arr[lIdx++];
        else if (lIdx == mid)
            tmp[i] = arr[rIdx++];
        else if (arr[lIdx] <= arr[rIdx])
            tmp[i] = arr[lIdx++];
        else
            tmp[i] = arr[rIdx++];
    }
    for (int i = start; i < end; i++)
        arr[i] = tmp[i];
}

void merge_sort(int start, int end)
{
    if (end - start == 1)
        return;

    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}