/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, m;
int DP[12][2000][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos,int rem, int f){
    //if(cnt > k) return 0;
    //cout<<pos<<"==>"<<<<"\n";
    if(pos == num.size()){
        if(rem == 0) return 1;
        return 0;
    }
    if(DP[pos][rem][f] != -1) return DP[pos][rem][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }
    //cout<<pos<<"==>"<<LMT<<"\n";
    //for(int i=0; i<num.size(); i++) cout<<num[i]<<" ";
    //cout<<"\n";

    if(pos%2){
        //cout<<"jhkdsj "<<pos<<" ==> \n";
        if(d>LMT) return DP[pos][rem][f]=0;
        return DP[pos][rem][f] = call(pos+1,(rem*10+d)%m,f|(d<LMT));    
    }
    //cout<<endl;
    //cout<<res<<"\n";
    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        
        if(dgt==d)continue;
        int nf = f;
        int nrem = (rem*10+dgt)%m;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        //if(dgt == d) ncnt++;
        res += call(pos+1, nrem, nf);
        //cout<< pos<<"==> "<< dgt <<" ==> "<< nrem<<"\n"; 
    }

    return DP[pos][rem][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity
    if(num.size()==0)num.push_back(0);
    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> m >> d >> a >> b;
    //if(m==0)m=1;
    ///cout<<solve(0)<<"\n";
    int res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}