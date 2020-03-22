#include<bits/stdc++.h>

using namespace std;
#define ll long long

typedef pair<int, int> pii;

int const lmt = 2e5+6;
string a[101],s;
map<string, ll > occ;
ll zero[101],one[101],diff[101];
int n,m,p;
ll mc=INT_MAX;
string ck;

void back(int i){
    if(i==p){
        //cout<<ck<<"\n";
        if(occ.find(ck)==occ.end()){
            ll cnt=0;
            for(int i=0; i<p; i++){
                if(ck[i]=='0')cnt+=one[i];
                else cnt+=zero[i];
            }
            mc = min(mc,cnt);
        }
        return;
    }
    back(i+1);
    ck[i]='1';
    back(i+1);
    ck[i]='0';
}

int main(){
    freopen("kkk.in","r",stdin);
    freopen("pkk.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        occ.clear();
        cin>>n>>m>>p;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<m; i++){
            cin>>s;
            occ[s]++;
        }
        for(int i=0; i<p; i++){
            zero[i]=0; one[i]=0; diff[i]=0;
            for(int j=0; j<n; j++){
                if(a[j][i]=='0'){
                    zero[i]++;
                }else{
                    one[i]++;
                }
            }
        }
        ck = "";
        for(int i=0; i<p; i++)ck+='0';
        mc=1ll*n*p + 8;
        back(0);
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<mc<<"\n";
        //
        cout<<"\n";
    }
}