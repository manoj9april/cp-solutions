#include<iostream>
#include<bits/stdc++.h>
using namespace std::chrono; 

#define ll long long
using namespace std;

int const lmt=15;
ll a[lmt],b[lmt][5],vis[lmt];
ll n; 
ll ans;

void go(int pos, int dir, int cnt, int type, int qnt, int dis){
    if(cnt==n || dis>ans){
        ans = min(ans, dis-1ll);
    }
    else if(pos == 0 || pos == n+1){
        type = pos;
        dir = -dir;
        qnt=2;
        go(pos+dir, dir, cnt, type, qnt, dis+1); // change direction and go forward
    }
    else if(vis[pos] || a[pos]!=type){
        go(pos+dir, dir, cnt, type, qnt, dis+1); //dont do anything go forward
    }else{
        go(pos+dir, dir, cnt, type, qnt, dis+1); // dont do anything go forward
        vis[pos]=1;
        go(pos-dir, -dir, cnt+1, qnt==1?1:type, qnt-1, dis+1); // fill and move back
        go(pos+dir, dir, cnt+1, qnt==1?1:type, qnt-1, dis+1); // fill and move forward
        vis[pos]=0;
    } 
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    
    
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            if(a[i]==1)a[i]=0;
            else a[i]=n+1;
        }
        ans = n*n+6;
        go(1,1,0,0,2,1);
        cout<<ans<<"\n";
    }
    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time: "
         << duration.count()/1000/1000.0 << " seconds" << endl; 
    
}
