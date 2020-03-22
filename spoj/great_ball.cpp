#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[10000005];

int main(){
    ios::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        memset(arr,0,sizeof arr);
        int n; cin>>n;
        int st,end,mend=0;
        while(n--){
            cin>>st>>end;
            mend = max(mend, end);
            arr[st]++;
            arr[end]--;
        }
        ll ans=0;
        ll best=0;
        for(int i=0; i<=mend; i++){
            ans += arr[i];
            best = max(best, ans);
        }
        cout<<best<<"\n";
    }
}
