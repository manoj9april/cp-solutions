#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
	freopen("ab.in","r",stdin);
	freopen("sample.out","w",stdout);     
	int test; cin>>test;
	//cout<<test<<"\n";
	for(int t=1;t<=test;t++)
	{                       //cout<<test<<"\n";
		ll n,o,d; cin>>n>>o>>d;
		//cout<<n<<" ";
		ll x[n]; ll a,b,c,m,L ;
		cin>>x[0]>>x[1]>>a>>b>>c>>m>>L;
		for(int i=2;i<n;i++)
		x[i]=(a*x[i-1]+b*x[i-2]+c)%m;
 
 
 
		ll s[n];   L=0;
		for(int i=0;i<n;i++)
		{
			s[i]=x[i]+L;
			//cout<<s[i]<<" ";
		}    
 
		int l=0; int r=0;
		ll ma=-100000000;
		int no=0; ll sum=0;
		no=s[0]%2==1?1:0;
		sum=s[0];
		while(l<n && r<n)
		{
			bool flag=false;
			while(r+1<n && sum+s[r+1]<=d && no+s[r+1]%2<=o)
			{
				r++; sum+=s[r];
				no+=s[r]%2;
				flag=true;
			}
			if(no<=o && sum<=d)
			ma=max(ma,sum);
			sum-=s[l];
			no-=s[l]%2;
			l++;
		}   
		cout<<"Case #"<<t<<": ";
		if(ma== -100000000)
		cout<<"IMPOSSIBLE";
		else
		cout<<ma;
		cout<<"\n";
	}
	return 0;
}