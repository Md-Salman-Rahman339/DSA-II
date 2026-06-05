#include<iostream>
using namespace std;

int parent[100];
int rnk[100];
long long compValue[100];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
        compValue[i] = 1; // each company starts with value 1
    }
}

int Find(int x)
{
    if(x == parent[x])
        return x;

    parent[x] = Find(parent[x]);
    return parent[x];
}

// now returns whether merged or not handled inside
void Union(int x, int y, int bonus)
{
    int px = Find(x);
    int py = Find(y);

    if(px == py)
    {
        cout << "ALREADY MERGED" << endl;
        return;
    }

    // compute new value
    long long newValue = compValue[px] + compValue[py] + bonus;

    // union by rank
    if(rnk[px] > rnk[py])
    {
        parent[py] = px;
        compValue[px] = newValue;
    }
    else if(rnk[py] > rnk[px])
    {
        parent[px] = py;
        compValue[py] = newValue;
    }
    else
    {
        parent[py] = px;
        rnk[px]++;
        compValue[px] = newValue;
    }

    cout << newValue << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    init(n);

    for(int i=0; i<m; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;

        Union(a, b, v);
    }

    return 0;
}