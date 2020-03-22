#include<bits/stdc++.h>

using namespace std;
#define ll long long

string arr[51];
bool ck[51];
int main(){
    freopen("tourist.in","r",stdin);
    freopen("tourist.out","w",stdout);
    int t; cin>>t;
    ll n,k,v;
    for(int tt=1; tt<=t; tt++){
        cin>>n>>k>>v;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            ck[i]=false;
        }
        ll st=(k*(v-1))%n;
        for(int i=0; i<k; i++){
            ck[(st+i)%n]=true;
        }
        cout<<"Case #"<<tt<<": ";
        for(int i=0; i<n; i++){
            if(ck[i]){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
    }
}