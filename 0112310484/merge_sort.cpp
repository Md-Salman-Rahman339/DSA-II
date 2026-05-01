#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    // [0..6] => 6-0+1 => length
    // endIdx - startIdx +1
    int n1 = mid - low + 1;
    int n2 = high - (mid + 1) + 1; // or, n2 = high-mid

    // Create temp arrays and copy data
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    // Compare and merge back into arr[]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy any remaining elements
    while (j < n2)
        arr[k++] = right[j++];
    while (i < n1)
        arr[k++] = left[i++];
}

void mergeSort(int arr[], int low, int high)
{
    // Base Case: Single Element
    if (low == high)
        return;

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Combine
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {7, 4, 3, 9, 5, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}