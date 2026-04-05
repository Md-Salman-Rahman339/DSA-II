#include <iostream>
#include <vector>
using namespace std;

int comp = 0;

void findMinMax(int arr[], int low, int high,
                int &mn, int &mx,
                vector<int> &minPos,
                vector<int> &maxPos)
{
  
    if (low == high) {
        mn = mx = arr[low];
        minPos.push_back(low);
        maxPos.push_back(low);
        return;
    }

    int mid = (low + high) / 2;

  
    int lmn, lmx;
    vector<int> lminPos, lmaxPos;
    findMinMax(arr, low, mid, lmn, lmx, lminPos, lmaxPos);

    // Right part
    int rmn, rmx;
    vector<int> rminPos, rmaxPos;
    findMinMax(arr, mid + 1, high, rmn, rmx, rminPos, rmaxPos);

    comp += 2; 

    if (lmx > rmx) {
        mx = lmx;
        maxPos = lmaxPos;
    }
    else if (rmx > lmx) {
        mx = rmx;
        maxPos = rmaxPos;
    }
    else {
        mx = lmx;
        maxPos = lmaxPos;
        maxPos.insert(maxPos.end(), rmaxPos.begin(), rmaxPos.end());
    }

   
    if (lmn < rmn) {
        mn = lmn;
        minPos = lminPos;
    }
    else if (rmn < lmn) {
        mn = rmn;
        minPos = rminPos;
    }
    else {
        mn = lmn;
        minPos = lminPos;
        minPos.insert(minPos.end(), rminPos.begin(), rminPos.end());
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int arr[n * m];

     
        for (int i = 0; i < n * m; i++)
            cin >> arr[i];

        int mn, mx;
        vector<int> minPos, maxPos;
        comp = 0;

        findMinMax(arr, 0, n * m - 1, mn, mx, minPos, maxPos);


        cout << "Peak load : " << mx << "% at "
             << maxPos.size() << " location(s): ";

        for (int idx : maxPos) {
            cout << "(server " << idx / m + 1
                 << ", time " << idx % m + 1 << ") ";
        }
        cout << endl;


        cout << "Min load : " << mn << "% at "
             << minPos.size() << " location(s): ";

        for (int idx : minPos) {
            cout << "(server " << idx / m + 1
                 << ", time " << idx % m + 1 << ") ";
        }
        cout << endl;

  
        cout << "Comparisons: " << comp << endl;
    }
}