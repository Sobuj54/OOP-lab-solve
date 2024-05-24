#include <bits/stdc++.h>
using namespace std;

void maxMin(int arr[], int low, int high, int &max, int &min)
{
    if (low == high)
    {
        min = arr[low];
        max = arr[low];
    }
    else if (low == high - 1)
    {
        if (arr[low] < arr[high])
        {
            max = arr[high];
            min = arr[low];
        }
        else
        {
            max = arr[low];
            min = arr[high];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;
        maxMin(arr, low, mid, max1, min1);
        maxMin(arr, mid + 1, high, max2, min2);

        max = (max1 < max2) ? max2 : max1;
        min = (min1 < min2) ? min1 : min2;
    }
}

int main()
{
    int arr[5] = {10, 5, 100, 23, 54};
    int max, min;
    maxMin(arr, 0, 4, max, min);
    cout << "max: " << max << endl
         << "min: " << min << endl;
    return 0;
}