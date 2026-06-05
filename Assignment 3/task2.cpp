#include <bits/stdc++.h>
using namespace std;

int minkey(vector<int> &key, vector<bool> &mstSet) {
    int minVal = INT_MAX, min_index = -1;

    for (int i = 0; i < key.size(); i++) {
        if (!mstSet[i] && key[i] < minVal) {
            minVal = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(vector<vector<int>>& graph, int V, int tc) {

    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    int totalWeight = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minkey(key, mstSet);

        if (u == -1) {
            cout << "Case " << tc << ": NETWORK FAILURE" << endl;
            return;
        }

        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < V; v++) {

            if (graph[u][v] &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Case " << tc << ": " << totalWeight << endl;
}

int main() {

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int N, M;
        cin >> N >> M;

        vector<vector<int>> graph(N, vector<int>(N, 0));

        for (int i = 0; i < M; i++) {

            int u, v, w;
            cin >> u >> v >> w;

            u--;
            v--;

            graph[u][v] = w;
            graph[v][u] = w;
        }

        primMST(graph, N, tc);
    }

    return 0;
}