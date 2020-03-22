#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){
    int t; cin>>t;
    while(t--){
        int x,n;
        cin>>x>>n;

        bool marked[n+1];
        memset(marked, false, sizeof marked);

        ll sum = 1LL*n*(n+1)/2 - x;

        if(sum%2!=0 || n==2 || n==3){
            cout<<"impossible\n";
            continue;
        }
        sum /= 2;
        marked[x]=true;
        bool ok =true;
        ll p = n;
        while(sum>0){
            if(sum<=p){
                if(sum==x){
                    if(!marked[p] && !marked[x+1] && p!=x+1){
                        marked[p+1]=false;
                        marked[p]=true;
                        marked[x+1]=true;
                    }else{
                        marked[1]=true;
                        marked[x-1]=true;
                    }
                }else{
                    marked[sum]=true;
                }
                sum=0;
            }
            else if(sum>p){
                if(p!=x){
                    sum -= p;
                    marked[p]=true;
                }
                p--;
            }
        }
        for(int i=1; i<=n; i++){
            if(i==x) cout<<"2";
            else cout<<(marked[i]?"0":"1");
        }
        cout<<"\n";
    }
}