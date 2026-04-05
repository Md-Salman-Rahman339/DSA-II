#include <iostream>
using namespace std;

void solve(int arr[], int low, int high,
           int &maxLen, int &start, int &end,
           int &prefixLen, int &suffixLen) {


    if (low == high) {
        if (arr[low] > 0) {
            maxLen = prefixLen = suffixLen = 1;
            start = end = low;
        } else {
            maxLen = prefixLen = suffixLen = 0;
            start = end = -1;
        }
        return;
    }

    int mid = (low + high) / 2;

    int lMax, lStart, lEnd, lPre, lSuf;
    int rMax, rStart, rEnd, rPre, rSuf;

    solve(arr, low, mid, lMax, lStart, lEnd, lPre, lSuf);
    solve(arr, mid + 1, high, rMax, rStart, rEnd, rPre, rSuf);


    if (lPre == (mid - low + 1))
        prefixLen = lPre + rPre;
    else
        prefixLen = lPre;

    if (rSuf == (high - mid))
        suffixLen = rSuf + lSuf;
    else
        suffixLen = rSuf;

    int crossLen = lSuf + rPre;


    maxLen = lMax;
    start = lStart;
    end = lEnd;


    if (rMax > maxLen) {
        maxLen = rMax;
        start = rStart;
        end = rEnd;
    }


    if (crossLen > maxLen) {
        maxLen = crossLen;
        start = mid - lSuf + 1;
        end = mid + rPre;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int maxLen, start, end, pre, suf;

        solve(arr, 0, n - 1, maxLen, start, end, pre, suf);

        if (maxLen == 0) {
            cout << "No profitable period found." << endl;
        } else {
            cout << "Longest consecutive profit period = "
                 << maxLen << " months" << endl;

            cout << "Month range = {";
            for (int i = start; i <= end; i++) {
                cout << "M" << i + 1;
                if (i != end) cout << ", ";
            }
            cout << "}" << endl;
        }
    }
}