#include<iostream>
using namespace std;

int n = 3;
int W = 5;
int weight[3] = {2, 2, 3};
int value[3] = {6, 10, 12};

int knapsack_01(int dp[][6])
{
    for(int i=0; i<=n; i++)
        dp[i][0] = 0; //capacity = 0
    for(int w=0; w<=W; w++)
        dp[0][w] = 0; //no items = 0
    for(int i=1; i<=n; i++)
        for(int w=1; w<=W; w++)
            if(weight[i-1]>w)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] =
                max(dp[i-1][w],
                    value[i-1]+dp[i-1][w-weight[i-1]]);
    return dp[n][W];
}

int main()
{
    int dp[n+1][6];
    int result = knapsack_01(dp);
    cout<<result<<endl;
}

