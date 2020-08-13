#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxWater(int arr[], int n)
{
    int res = 0;
    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water (only if it is positive)
        int amount = (min(left, right) - arr[i]);
        if (amount > 0)
            res += amount;
    }

    return res;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}
