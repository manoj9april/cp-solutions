#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int szm =int(ceil(n*1.0/2)); 
        int szt = n/2;
        int motu[szm];
        int tomu[n/2];
        int p=0,q=0,ms=0,ts=0;

        for(int i=0; i<n; i++){
            if(i%2==0){
                cin>>motu[p];
                ms += motu[p];
                p++;
            }else{
                cin>>tomu[q];
                ts += tomu[q];
                q++;
            }
        }
        
        if(ts>ms){
            cout<<"YES\n";
        }else{
            sort(motu,motu+szm);
            sort(tomu,tomu+szt);
            int df,sdiff = ms-ts;
            for(int j=0; j<szt && j<k; j++){
                
                df = 2*(motu[szm-1-j]-tomu[j]);
                if(df<0){
                    //cout<<"NO\n";
                    break;
                }
                sdiff -= df;

                if(sdiff<0){
                    //cout<<"YES\n";
                    break;
                }
            }
            cout<<(sdiff>=0?"NO":"YES")<<"\n";
        }
    }
}