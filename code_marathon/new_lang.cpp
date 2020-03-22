#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const lmt = 2;
int const M = 1e9 +7;

struct mat{
    int r,c;
    ll a[lmt][lmt];

    mat(int n, int m){
        r=n; c=m;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                a[i][j]=0;
            }
        }
    }
};

mat mul(mat A, mat B){
    mat res(A.r, B.c);

    for(int i=0; i<A.r; i++){
        for(int j=0; j<B.c; j++){
            for(int k=0; k<A.c; k++){
                res.a[i][j] += (A.a[i][k]*B.a[k][j])%M;
            }
        }
    }

    return res;
}

mat power(mat A, ll n){
    mat res(A.r,A.c);
    // ini res = I  (identity mat)
    for(int i=0; i<A.r; i++){
        res.a[i][i]=1;
    }

    while(n){
        if(n&1) res = mul(res,A);
        A = mul(A,A);
        n = (n>>1);
    }

    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n;  cin>>n;
        if(n==1) { cout<<4<<"\n"; continue;}
        else if(n==2){ cout<<15<<"\n"; continue; }
        //cout<<"hjgd\n";
        mat f(2,1);
        f.a[0][0]=15;  //f2
        f.a[1][0]=4;  //f1

        mat K(2,2);
        K.a[0][0]=3;  K.a[0][1]=3;
        K.a[1][0]=1;  K.a[1][1]=0;
        //cout<<"hjgd\n";
        mat res = power(K,n-2);  // fn fn-1
        //cout<<"hjgd\n";
        res = mul(res,f);

        cout<<res.a[0][0]<<"\n";
    }
}