#include <bits/stdc++.h>

using namespace std;

int cost[105];
int fun[105];

int cosst, ffun;
int dp[102][505];

int solve(int i, int value)
{
    if (i < 0 || value < 5)
        return 0;
    bool f = false;
    if (dp[i][value] != -1)
        return dp[i][value];

    else
    {
        if(cost[i]>value){
            return dp[i][value] = solve(i - 1, value);
        }
        else{
            dp[i - 1][value] = solve(i - 1, value);
            dp[i - 1][(value - cost[i])] = solve(i - 1, value - cost[i]);

            if (fun[i] + dp[i - 1][value - cost[i]] > dp[i - 1][value])
            {
                cosst += cost[i];
                return dp[i][value] = fun[i] + dp[i - 1][value - cost[i]];
            }
            else
            {
                return dp[i][value] = solve(i - 1, value);
            }
        }
        /*
        if ((value - cost[i]) >= 5)
        {
            dp[i - 1][(value - cost[i])] = solve(i - 1, value - cost[i]);
            f = true;
        }
        dp[i - 1][value] = solve(i - 1, value);
        if (f && fun[i] + dp[i - 1][value - cost[i]] > dp[i - 1][value])
        {
            cosst += cost[i];
            return dp[i][value] = fun[i] + dp[i - 1][value - cost[i]];
        }
        else
        {
            return dp[i][value] = dp[i - 1][value];
        }
        */
    }
}

int main()
{
    int bud, n;
    cin >> bud >> n;
    while (bud && n)
    {

        memset(dp, -1, sizeof(dp));
        cosst = 0;
        //cout<<"hhhh\n";
        for (int i = 0; i < n; i++)
        {
            cin >> cost[i] >> fun[i];
        }
        //cout<<"hhhh\n";
        ffun = solve(n - 1, bud);
        cout << cosst << " " << ffun << "\n";

        cin >> bud >> n;
    }
}