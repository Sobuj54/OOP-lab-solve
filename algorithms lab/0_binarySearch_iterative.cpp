#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {10, 25, 5, 2, 74}, search;
    cin >> search;
    sort(arr, arr + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int low = 0, high = 4, flag = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            cout << "match found at index :" << mid;
            flag += 1;
            break;
        }
        else if (search > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (flag == 0)
    {
        cout << "No match found." << endl;
    }
    return 0;
}