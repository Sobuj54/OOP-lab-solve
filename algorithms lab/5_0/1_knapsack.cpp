#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit, weight;

    Item(int profit = 0, int weight = 0) : profit(profit), weight(weight) {}
};

int knapSack(Item items[], int n, int capacity)
{
    int v[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                v[i][w] = 0;
            }
            else if (items[i - 1].weight <= w)
            {
                v[i][w] = max(v[i - 1][w], v[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            }
            else
            {
                v[i][w] = v[i - 1][w];
            }
        }
    }

    return v[n][capacity];
}

int main()
{
    int w = 8, n = 4;
    Item items[] = {{1, 2}, {2, 3}, {5, 4}, {6, 5}};
    int mxProfit = knapSack(items, n, w);
    cout << "Maximum profit: " << mxProfit << endl;
    return 0;
}