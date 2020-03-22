#include<bits/stdc++.h>

using namespace std;

int lcs[1001][1001];
string f,s;
vector<char> sol;
int n,m;

void solve(int i,int j){
    if(i==0 || j==0) return;
    if(f[i-1]==s[j-1]){
        sol.push_back(f[i-1]);
        solve(i-1,j-1);
    }else{
        if(lcs[i-1][j]>lcs[i][j-1]) solve(i-1,j);
        else solve(i,j-1);
    }
}

int main(){
    
    while(cin>>f){
        cin>>s;
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        n = f.length();
        m = s.length();

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) lcs[i][j]=0;
                else if(f[i-1]==s[j-1])lcs[i][j]=lcs[i-1][j-1]+1;
                else{
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        sol.clear();
        solve(n,m);
        sort(sol.begin(), sol.end());
        int p = sol.size();
        for(int i=0; i<p; i++){
            cout<<sol[i];
        }
        cout<<"\n";
    }
}