#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&a,int s,int e){
    int i=s-1,pivot=a[e];
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[e],a[i]);
    return i;
}

void QuickSort(vector<int>&a,int s,int e){
    if(s<e){
        int pivot=partition(a,s,e);
        QuickSort(a,s,pivot-1);
        QuickSort(a,pivot+1,e);


    }
}
int main(){
    vector<int>arr;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);

    }
    QuickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
