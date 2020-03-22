#include<bits/stdc++.h>

using namespace std;
#define ll long long

typedef pair<int, int> pii;

int const lmt = 2e5+6;
string a[101],s;
map<string, ll > occ;
ll zero[101],one[101],diff[101];
priority_queue< pii , vector<pii>, greater<pii> > q;
int n,m,p;
ll mc=INT_MAX;
string ck;
bool found;
void back(int i){
    if(found) return;
    if(i==p){
        //cout<<ck<<"\n";
        if(occ.find(ck)==occ.end()){
            ll cnt=0;
            for(int i=0; i<p; i++){
                if(ck[i]=='0')cnt+=one[i];
                else cnt+=zero[i];
            }
            mc = min(mc,cnt);
            //found=true;
        }
        return;
    }
    pii pk = q.top(); q.pop();
    int x = pk.second;
    if(ck[x]=='1'){
        ck[x]='0';
    }else{
        ck[x]='1';
    }
    back(i+1);
    if(ck[x]=='1'){
        ck[x]='0';
    }else{
        ck[x]='1';
    }
    back(i+1);
    q.push(pk);
}


int main(){
    freopen("kkk.in","r",stdin);
    freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        found=false;
        occ.clear();
        while(q.size())q.pop();
        int n,m,p;
        cin>>n>>m>>p;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<m; i++){
            cin>>s;
            occ[s]++;
            /*
            for(int j=0; j<p; j++){
                if(s[j]=='0')zb[j]=1;
                else ob[j]=1;
            }*/
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
            diff[i] = abs(zero[i]-one[i]);
            q.push(make_pair(diff[i],i));
        }
        string ans="";
        for(int i=0; i<p; i++){
            if(zero[i]>=one[i]){
                ans+='0';
            }else{
                ans+='1';
            }
        }
        /*ck = "";
        for(int i=0; i<p; i++)ck+='0';
        */
        ck=ans;
        mc=1ll*n*p + 8;
        if(occ[ck])back(0);
        else{
            ll cnt=0;
            for(int i=0; i<p; i++){
                if(ck[i]=='0')cnt+=one[i];
                else cnt+=zero[i];
            }
            mc=cnt;
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<mc<<"\n";
        //
        cout<<"\n";
    }
}