#include <bits/stdc++.h>

using namespace std ;

int main(){
    long long n; cin>>n;
    while(n){
        multiset<long long >  st;
        long long ans =0;
        long long a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            st.insert(a[i]);
        }
        ans = 1LL*(*st.begin())*n;

        int l=0; int r=n-1;
        for(int i=1; i<n; i++){
            if(a[l]<a[r]){
                st.erase(st.find(a[l]));
                l++;
            }else{
                st.erase(st.find(a[r]));
                r--;
            }
            ans = max(ans,1LL*(*st.begin())*(n-i) );
        }
        cout<<ans<<"\n";

        cin>>n;
    }
}