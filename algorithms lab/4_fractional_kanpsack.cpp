#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;

    Item(int value = 0, int weight = 0) : value(value), weight(weight) {}
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double knapSack(Item arr[], int n, int w)
{
    sort(arr, arr + n, cmp);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + arr[i].weight <= w)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = w - currentWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
        }
    }
    return finalValue;
}

int main()
{
    int w = 10;
    Item arr[] = {{10, 5}, {15, 4}, {12, 6}};
    int size = sizeof(arr) / sizeof(arr[0]);

    double x = knapSack(arr, size, w);
    cout << "Total profit: " << x;
    return 0;
}