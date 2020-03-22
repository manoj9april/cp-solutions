#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(int a, int b){
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t; cin>>t;
    ll p,q,b,h;
    while(t--){
        cin>>p>>q>>b;
        h = gcd(p,q);
        p = p/h;
        q = q/h;

        b = gcd(q,b);
        while(b!=1){
            while(q%b==0) q = q/b;
            b = gcd(q,b);
        }

        cout<<(q==1?"Finite":"Infinite")<<"\n";
    }
}