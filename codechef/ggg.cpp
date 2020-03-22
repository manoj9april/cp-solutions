#include<bits/stdc++.h>

using namespace std;

int main(){
    string s="abc";
    s="abcd";
    cout<<s;
}

if (last == i - 1)
{
    if (maxx + a[i] > dp[i - 1])
    {
        dp[i] = maxx + a[i];
        maxx = dp[i];
        maxi = i;
        last = i;
    }
    else
    {
        dp[i] = dp[i - 1];
    }
}
else
{
    dp[i] = maxx + a[i];
    maxx = dp[i];
    maxi = i;
    last = i;
}