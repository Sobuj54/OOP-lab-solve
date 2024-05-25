#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int i = low, j = high;

        while (i < j)
        {
            while (i <= high && arr[i] <= pivot)
                i++;
            while (j >= low && arr[j] > pivot)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[low]);

        int pi = j;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    const int SIZE = 10000;
    int arr1[SIZE];
    int arr2[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        int num = rand() % SIZE;
        arr1[i] = num;
        arr2[i] = num;
    }

    // time calculation for bubble sort
    clock_t start = clock();
    bubbleSort(arr1, SIZE);
    clock_t end = clock();
    double bubbleDuration = double(end - start) / CLOCKS_PER_SEC;

    // quicksort time calculation
    start = clock();
    quickSort(arr2, 0, SIZE - 1);
    end = clock();
    double quickDuration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Bubble sort duration: " << bubbleDuration << " seconds" << endl;
    cout << "Quick sort duration: " << quickDuration << " seconds" << endl;
    return 0;
}