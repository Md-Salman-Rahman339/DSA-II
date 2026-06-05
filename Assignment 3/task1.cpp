#include <bits/stdc++.h>
using namespace std;

long long coinChangeWays(vector<int>& coins, int amount)
{
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for(int coin : coins)
    {
        for(int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main()
{
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        int n, S;
        cin >> n >> S;
        vector<int> coins(n);
        for(int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        long long result = coinChangeWays(coins, S);
        cout << "Case " << tc
             << ": Total Ways = "
             << result << endl;
    }

    return 0;
}