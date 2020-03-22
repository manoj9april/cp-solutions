#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair< pii, int> piii;

#define e first.first
#define st first.second
#define pr second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        piii arr[n+1];
        for(int i=1; i<=n; i++){
            cin>>arr[i].st>>arr[i].e>>arr[i].pr;
            arr[i].e += arr[i].st;
        }
        sort(arr+1,arr+n+1);
        arr[0].st=arr[0].e=arr[0].pr=0;
        int dp[n+1];
        dp[0]=0;

        int lo,hi,mid;
        for(int i=1; i<=n; i++){
            lo=0,hi=i-1;
            while(lo<=hi){
                mid = lo + (hi-lo)/2;
                if(arr[mid].e<=arr[i].st) lo =mid+1;
                else hi = mid-1;
            }
            dp[i] = max(dp[i-1],arr[i].pr+dp[hi]);
        }

        cout<<dp[n]<<"\n";
    }
}