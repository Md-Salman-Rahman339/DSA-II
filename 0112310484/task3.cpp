#include <iostream>
using namespace std;

int comp = 0;

int partition(string arr[], int low, int high){
    string pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        comp++;
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void QuickSort(string arr[], int low, int high){
    if(low >= high) return;

    int pi = partition(arr, low, high);

    QuickSort(arr, low, pi-1);
    QuickSort(arr, pi+1, high);
}

int main(){
    int T; cin >> T;

    while(T--){
        int n; cin >> n;

        string arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        comp = 0;
        QuickSort(arr,0,n-1);

        for(int i=0;i<n;i++)
            cout << arr[i] << endl;

        cout << "Comparisons: " << comp << endl;
    }
}