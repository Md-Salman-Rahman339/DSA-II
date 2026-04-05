#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int result[])
{
    if (low == high)
    {
        result[0] = arr[low];
        result[1] = arr[low];
        return;
    }

    if (low == high - 1)
    {
        result[0] = min(arr[low], arr[high]);
        result[1] = max(arr[low], arr[high]);
        return; 
    }

    int mid = (low + high) / 2;

    int left[2], right[2];

    findMinMax(arr, low, mid, left);
    findMinMax(arr, mid + 1, high, right);

    result[0] = min(left[0], right[0]);
    result[1] = max(left[1], right[1]);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    int result[2];
    findMinMax(arr, 0, n-1, result);

    cout << "Minimum = " << result[0]
         << ", Maximum = " << result[1] << endl;
}