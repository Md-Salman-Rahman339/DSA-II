#include <iostream>
using namespace std;

// result[0] => Min
// result[1] => max
void findMinMax(int arr[], int low, int high, int result[])
{
    // Base Case (1 element)
    if (low == high)
    {
        result[0] = arr[low];
        result[1] = arr[low];
        return;
    }

    // Base Case (2 elements)
    if (low == high - 1)
    {
        result[0] = min(arr[low], arr[high]);
        result[1] = max(arr[low], arr[high]);
    }

    // Divide
    int mid;
    mid = (low + high) / 2;

    int left_result[2], right_result[2];

    // Conquer
    findMinMax(arr, low, mid, left_result);
    findMinMax(arr, mid + 1, high, right_result);

    // Combine
    result[0] = min(left_result[0], right_result[0]);
    result[1] = max(left_result[1], right_result[1]);
}

int main()
{
    int arr[] = {7, 4, 3, 9, 5, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[2];
    findMinMax(arr, 0, n - 1, result);
    cout << "Min: " << result[0] << endl;
    cout << "Max: " << result[1] << endl;
}