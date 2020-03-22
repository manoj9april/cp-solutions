#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

int main(){
    int n; cin>>n;
    while(n){
    stack<int> st;
    int left[n],a[n],right[n];
    for(int i=0; i<n; i++){
        left[i]=0;right[i]=n-1;
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        while(!st.empty() && a[i]<=a[st.top()]){
            st.pop();
        }
        if(!st.empty())left[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && a[i]<=a[st.top()]){
            st.pop();
        }
        if(!st.empty())right[i]=st.top()-1;
        st.push(i);
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        ans = max(ans, 1LL*(right[i]-left[i]+1)*a[i]);
    }

    cout<<ans<<"\n";
    cin>>n;
    }
}