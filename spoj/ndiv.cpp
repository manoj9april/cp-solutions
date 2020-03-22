#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt = 5*1e5+5;

int arr[1000001];

void seive(){
    
    //memset(arr, 0, sizeof arr);
    for(ll i=2; i<=1000000; i++){
        if(arr[i]==0){
            //arr[i]=1;
            for(ll j=i; j<=1000000; j+=i){
                arr[j]++;
            }
        }
    }
    arr[1]=0;
}
int block[1001][100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    seive();
    
    //memset(block, 0, sizeof block);
    int idx=0;
    for(int i=1; i<=1000000; i++){
        if(i%1000==0) idx++;

        block[idx][arr[i]]++;
    }
    //for(int i=1; i<=10; i++) cout<<arr[i]<<" ";
    //cout<<endl;
    int t=1; cin>>t;
    while(t--){
        ll a,b,n; cin>>a>>b>>n;

        if(n==0){
            
            cout<<(a==1?1:0)<<"\n"; continue;
        }
        
        int cnt=0;
        /*
        for(int i=a; i<=b; i++){

               if(arr[i] == n) cnt++;
        }*/
        
        int st=a;
        while(st%1000!=0 && st<=b){
            if(arr[st]==n)
                cnt ++;
            st++;
        }
        idx = st/1000;
        while(st+999<=b){
            cnt += block[idx][n];
            idx++;
            st += 1000;
        }

        while(st<=b){
            if(arr[st]==n)
                cnt ++; 
            st++;
        }
        cout<<cnt<<"\n";
    }

}