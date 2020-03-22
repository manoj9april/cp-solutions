#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t; cin>>t;
	while(t--){
		int n,ele,mx=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>ele;
			mx = max(ele,mx);
		}
		int a,b,c;
		cin>>a>>b>>c;
		long long ans = 1LL*(a-1)*mx;
		double anss=ans;
		printf("%0.9f\n",anss);
	}
}    