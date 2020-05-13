ll phi(ll n){
	ll ans=n;
	ll d=2;
	while(d*d<=n){
		if(n%d==0){
			ans -= ans/d;
			while(n%d==0) n /= d;
		}
		d++;
	}
	if(n>1)ans -= ans/n;
	return ans;
}