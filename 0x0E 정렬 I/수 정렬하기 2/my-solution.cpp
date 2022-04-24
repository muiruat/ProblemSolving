#include <iostream>
using namespace std;

int n;
int arr[1000000];
int tmp[1000000];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int idx1 = start;
    int idx2 = mid;
    for (int i = start; i < end; i++)
    {
        if (idx1 == mid)
            tmp[i] = arr[idx2++];
        else if (idx2 == end)
            tmp[i] = arr[idx1++];
        else if (arr[idx1] <= arr[idx2])
            tmp[i] = arr[idx1++];
        else
            tmp[i] = arr[idx2++];
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