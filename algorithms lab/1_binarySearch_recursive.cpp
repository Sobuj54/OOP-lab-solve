#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int l, int h, int s)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == s)
            return 1;
        else if (s < arr[mid])
            return binSearch(arr, l, mid - 1, s);
        else
            return binSearch(arr, mid + 1, h, s);
    }
    return 0;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int res = binSearch(arr, 0, n - 1, s);
    if (res > 0)
    {
        cout << "Match found.";
    }
    else
    {
        cout << "No match found";
    }

    return 0;
}