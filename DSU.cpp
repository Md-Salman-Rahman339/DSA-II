#include<iostream>
using namespace std;

int parent[100];
int rnk[100];

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
    int n = 5;
    init(n);
    Union(0,1);
    Union(0,2);
    cout<<Union(1,3)<<endl;
}
