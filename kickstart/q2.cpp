#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;

int kx[4]={-1,0,1,0};
int ky[4]={0,1,0,-1};

int main(){
    //freopen("sample.in","r",stdin);
    //freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        ll r,c; cin>>r>>c;
        string s[r];
        for(int i=0; i<r; i++) cin>>s[i];
        bool mp[r][c]={false};
        queue<int> q;
        ll ans[r][c];
        memset(ans,-1,sizeof ans);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(s[i][j]=='1') q.push(i),q.push(j),ans[i][j]=0;
                //cout<< ans[i][j] << " ";
                
            }
            //cout<<"\n";
        }
        int best =0;
        cout<<"hekjl\n";
        while(!q.empty()){
            int i = q.front(); q.pop();
            int j = q.front(); q.pop();

            for(int k=0; k<4; k++){
                int ni = i+kx[k];
                int nj = j+ky[k];
                if(ni<0 || ni>=r || nj<0 || nj >= c || ans[ni][nj]!=-1) continue;

                ans[ni][nj] = ans[i][j]+1;
                best = max(1ll*best,ans[ni][nj]);
                q.push(ni); q.push(nj);
            }

        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<best;
        //
        cout<<"\n";
    }
}
