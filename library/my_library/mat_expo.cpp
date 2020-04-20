ll const N,x;
ll tem[N][N],res[N][N];

void matpow(ll g[N][N], int ex){
	int i, j, k;
	if (ex == 1) return ;
	loop(i, x) loop(j, x) tem[i][j] = g[i][j];	// initialize tem properly to represent initial situation before any input
	matpow(g, ex/2);
	loop(i, x) loop(j, x) { res[i][j] = 0; loop(k, x) res[i][j] += g[i][k]*g[k][j]%mod;}
	loop(i, x) loop(j, x) res[i][j] %= mod;
	if (ex&1){
		loop(i, x) loop(j, x) { g[i][j] = 0; loop(k, x) g[i][j] += res[i][k]*tem[k][j]%mod;}
		loop(i, x) loop(j, x) g[i][j] %= mod;
	}
	else
		loop(i, x) loop(j, x) g[i][j] = res[i][j];
}



void matexpo(ll g[N][N], ll ex){
	int i, j, k;
	if (ex == 1) return ;
	ini(tem,0);
	loop(i, x) tem[i][i]=1;

	while(ex){
		if(ex&1){
			loop(i, x) loop(j, x) { res[i][j] = 0; loop(k, x) res[i][j] += tem[i][k]*g[k][j]%mod;}
			loop(i, x) loop(j, x) tem[i][j] = (res[i][j]%mod);
		}
		// g= g*g
		loop(i, x) loop(j, x) { res[i][j] = 0; loop(k, x) res[i][j] += g[i][k]*g[k][j]%mod;}
		loop(i, x) loop(j, x) g[i][j] = (res[i][j]%mod);

		ex = ex/2;

	}
	loop(i, x) loop(j, x) g[i][j] = (tem[i][j]%mod);

}
