#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
set<char> st;
map<char,int> mp;
int main(){
    int n; cin>>n;
    string a,b;
    cin>>a>>b;
    ll ans=0;
    for(int i=0; i<n/2 ;i++){
        st.clear();
        mp.clear();
        st.insert(a[i]);mp[a[i]]++;
        st.insert(b[i]);mp[b[i]]++;
        st.insert(a[n-1-i]);mp[a[n-1-i]]++;
        st.insert(b[n-1-i]);mp[b[n-1-i]]++;
        int sz = st.size();
        if(sz==1)continue;
        else if(sz==4)ans += 2;
        else if(sz==3){
            if(mp[a[i]]==1 || mp[a[n-1-i]]==1)ans++;
            else ans+=2;
        }
        else if(sz==2){
            int cnt[2],k=0;
            for(char c: st){
                cnt[k]=mp[c];
                k++;
            }
            if(cnt[0]!=cnt[1])ans++;
        }
    }
    if(n%2==1){
        if(a[n/2]!=b[n/2])ans++;
    }
    cout<<ans<<"\n";
}

