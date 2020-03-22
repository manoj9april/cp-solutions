#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int t; cin>>t;
    string a,b;
    while(t--){
        int n,m;
        cin>>n>>m;
        bool invalid=false,weak=false;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            bool ok;
            if(a=="correct"){
                ok=true;
                for(int j=0; j<m; j++){
                    if(b[j]=='0'){
                        ok=false; break;
                    }
                }
                if(!ok)invalid=true;
            }else{
                ok=false;
                for(int j=0; j<m; j++){
                    if(b[j]=='0'){
                        ok=true; break;
                    }
                }
                //cout<<(ok?"FINE\n":"WEAK\n");
                if(!ok)weak=true;
            }
        }
        if(invalid){
            cout<<"INVALID\n";
        }else if(weak){
            cout<<"WEAK\n";
        }else{
            cout<<"FINE\n";
        }
    }
}

