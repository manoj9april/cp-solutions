#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        int a[n];
        ll sum=0;
        bool found=false;
        int last =0,ans=200000;
        int neg=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]<0) neg++;
            sum += (long long)a[i];

            while(((neg>0 && a[i]>0) || neg>1 || sum>=d) && last<=i){

                if (sum >= d){
                    found = true;
                    ans = min(ans, i - last + 1);
                }
                if(a[last]<0) neg--;
                sum -= (long long)a[last++];
            }
        } 
        if(found)
            cout<<ans<<endl;
        else
            cout<<"-1\n";
    }

}