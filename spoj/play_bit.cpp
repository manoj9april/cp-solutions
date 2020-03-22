#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        n--;
        int nn = n;

        int i=-1,cnt=0;
        while(nn){
            if(nn&1) cnt++;
            nn >>= 1;
            i++;
        }
        if(k==0){
            cout<<"-1\n";
            continue;
        }
        if(k>=cnt){
            cout<<n<<"\n";
            continue;
        }
        nn = n;
        int bit = i;
        int itr=cnt-k;
        
        for( i=1; itr && i<=bit; i++){
            if(nn&(1<<i)){
                nn = nn^(1<<i);
                itr--;
            }
        }

        cout<<nn<<"\n";
    }
}