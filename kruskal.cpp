#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100];
int rnk[100];

struct edge {
    int u, v, w;
};

bool compare(edge a, edge b){
    return a.w < b.w;
}

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int Find(int x)
{
    if(x==parent[x])
        return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}

bool Union(int x, int y){
    int px = Find(x);
    int py = Find(y);
    if(px!=py){
        if(rnk[px]>rnk[py]){
            parent[py] = px;
        }
        else if(rnk[py]>rnk[px]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rnk[px]++;
        }
        return true;
    }
    return false;
}

int main(){
    int V = 6;
    vector<edge> edges = {
        {0, 2, 1},
        {1, 5, 1},
        {0, 1, 2},
        {2, 3, 2},
        {3, 5, 2},
        {2, 4, 3},
        {3, 4, 6}
    };
    sort(edges.begin(), edges.end(), compare);
    init(V-1);
    vector<edge> mst;
    int mst_weight=0;
    int edges_added = 0;
    for(edge e: edges){
        if (Union(e.u, e.v)){
            mst.push_back(e);
            mst_weight = mst_weight+e.w;
            edges_added++;
        }
        if(edges_added==V-1)
           break;
    }
    cout<<"MST weight: "<<mst_weight<<endl;
}
