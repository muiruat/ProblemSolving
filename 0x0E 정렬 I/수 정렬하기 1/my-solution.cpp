#include <iostream>
using namespace std;

int n;
int arr[1000];

void quick_sort(int start, int end)
{
    if (end - start <= 1)
        return;

    int pivot = arr[start];
    int l = start + 1;
    int r = end - 1;
    while (true)
    {
        while (l <= r && pivot >= arr[l])
            l++;
        while (l <= r && pivot <= arr[r])
            r--;
        if (l > r)
            break;
        swap(arr[l], arr[r]);
    }
    swap(arr[start], arr[r]);

    quick_sort(start, r);
    quick_sort(r + 1, end);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}