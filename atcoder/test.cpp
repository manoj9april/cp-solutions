/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char *k[])
{
	//Write code here
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n],ans=0;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>b[i];
		sort(a,a+n); //reverse(a,a+n);
		sort(b,b+n); //reverse(b,b+n);

        // for(int i=0; i<n; i++)cout<<a[i]<<" ";
        // cout<<"\n";
        // for(int i=0; i<n; i++)cout<<b[i]<<" ";
        // cout<<"\n";

        int idx=0;
        ans=0;
		for(int i=0; i<n; i++){
            while(idx<n && a[idx]<=b[i]) idx++;
            if(idx<n && a[idx]>b[i]) {ans++; idx++;}
        }
		cout<<ans<<"\n";
	}
}
