#include <bits/stdc++.h>
using namespace std;

int minChocolateDiff(vector<int>& A, int N, int M) {
    if (M == 0 || N == 0) return 0;
    if (N < M) return -1;

    sort(A.begin(), A.end());

    int min_diff = INT_MAX;

    for (int i = 0; i <= N - M; i++) {
        int diff = A[i + M - 1] - A[i];
        min_diff = min(min_diff, diff);
    }

    return min_diff;
}

int main() {
    int N ,M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    cout << minChocolateDiff(A, N, M) << endl;

    return 0;
}