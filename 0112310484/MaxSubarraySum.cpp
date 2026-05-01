#include<iostream>
using namespace std;

int maxCrossSum(int arr[], int low, int mid, int high)
{
    //Go LEFT from mid
    int cl=INT_MIN, sum=0;
    for(int i=mid; i>=low; i--)
    {
        sum = sum+arr[i];
        if(sum>cl) cl=sum;
    }

    //Go RIGHT after mid
    int cr=INT_MIN;
    sum=0;
    for(int i=mid+1; i<=high; i++)
    {
        sum = sum+arr[i];
        if(sum>cr) cr=sum;
    }
    return cl+cr;
}

int maxSubarraySum(int arr[], int low, int high)
{
    //Base case
    if(low==high)
        return arr[low];

    //divide
    int mid = (low+high)/2;

    //conquer
    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid+1, high);

    //combine
    int crossSum = maxCrossSum(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossSum);
}

int main()
{
    int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr,0,n-1)<<endl;
}
