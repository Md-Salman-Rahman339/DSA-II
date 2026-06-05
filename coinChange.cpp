#include<iostream>
using namespace std;

int coins[3] = {3, 5};
int amount = 7;
int INF = amount+1; //or INF = INT_MAX


int coinChange(int dp[])
{
    dp[0] = 0;
    for(int i=1; i<=amount; i++)
        dp[i] = INF;
    for(int i=1; i<=amount; i++)
        for(int coin: coins)
            if(coin <= i)
                dp[i] = min(dp[i], 1+ dp[i-coin]);
    if(dp[amount]==INF)
        return -1;
    else return dp[amount];
}

int main()
{
    int dp[amount+1];
    int result = coinChange(dp);
    if(result == -1)
        cout<<"Not Possible"<<endl;
    else
        cout<<"Min coins required =  "<<result<<endl;
}
