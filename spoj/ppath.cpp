#include<bits/stdc++.h>

using namespace std;

bool a[10000];

void fprime(){
    
    int j;
    memset(a,true,sizeof(a));
    for(int i=2; i<10000; i++){
        if(a[i]){
            j=2*i;
            while(j<10000){
                a[j] = false;
                j += i;
            }
        }
    }
}

long long path[10005];

int main(){
    int t; cin>>t;
    fprime();
    while(t--){
        int n,m;
        cin>>n>>m;
        long long int ans = -1;

        queue<int> q;
        if(n==m){
            ans=0;
            goto label;
        }
        memset(path,-1,sizeof path);
        q.push(n);
        path[n]=0;
        while(!q.empty()){
            int p = q.front();q.pop();
            for(int i=0; i<4; i++){
                int  mul = pow(10,i);
                int gg =10*mul;
                int dig = p%(gg);
                for(int j=0; j<=9; j++){
                    int c = p - (dig)*mul + j*mul ;
                    if(c>999 && a[c] && c!=p && path[c]==-1 ){
                        cout<<c<<" ";
                        path[c]=path[p]+1;
                         
                        if(c==m){
                            ans=path[c];
                            goto label;
                        }
                       q.push(c);
                    }
                }
                cout<<"*****"<<endl;
            }
            cout<<"----"<<endl;
        }

        label:

        if(ans==-1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<ans<<endl;
        }
    }

}