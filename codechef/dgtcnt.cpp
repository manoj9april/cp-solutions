/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll dig[10],ndig[10];
vector<ll> num;
ll a, b, d, k;
ll DP[12][1<<12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

ll call(ll pos, ll val, ll f){
    //if(val) return 0;

    if(pos == num.size()){
        if(val) return 0;
        return 1;
    }

    if(DP[pos][val][f] != -1) return DP[pos][val][f];
    ll res = 0;

    ll LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(ll dgt = 0; dgt<=LMT; dgt++){
        ll nf = f;
        ll nval=val;
        //ll ncnt = ndig[dgt];
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        //if(dgt == d) ncnt++,ndig[dgt]++;
        ndig[dgt]++;
        if(ndig[dgt]==dig[dgt]) nval=((1ll<<dgt)^nval);
        else if(ndig[dgt]==dig[dgt]+1) nval=((1ll<<dgt)^nval);
        res += call(pos+1, nval, nf);
        ndig[dgt]--;
    }

    return DP[pos][val][f] = res;
}

ll solve(ll b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    ll res = call(0, 0, 0);
    return res;
}

int main () {

    ll t; cin>>t;
    while(t--){
        cin >> a >> b;
        for(int i=0; i<=9; i++){
            cin>>dig[i];
        }
        ll res = solve(b) - solve(a-1);
        cout << res << endl;

    }
    return 0;
}