#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pp pair<int, pair<int,int> >
#define f first
#define s second

int const lmt = 1e6+6;
bool ck[lmt];
pp arr[30005];

set<int> st;

ll n,q;

void ini(){
    for(int i=1; i<=n; i++)st.insert(i);
}

bool check(ll mid){
    ini();
    for(int i=0; i<q; i++){
        ll a = arr[i].s.f;
        ll b = arr[i].s.s;
        ll cnt=0;
        while(cnt<mid){
            auto it = st.lower_bound(a);
            if(it == st.end()) return false;
            if(*it <= b){
                st.erase(it);
                cnt++;
            }else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    //freopen("sample.in","r",stdin);
    //freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        //ll n,q;
        cin>>n>>q;
        ll lo=lmt,hi=0;
        for(int i=0; i<q; i++){
            cin>>arr[i].s.f >> arr[i].s.s;
            arr[i].f = arr[i].s.s - arr[i].s.f+1;
            lo = min(lo,1ll*arr[i].f);
            hi = max(hi,1ll*arr[i].f);
        }
        sort(arr,arr+q);

        ll mid;
        while(lo<=hi){
           mid = lo + (hi-lo)/2;
           if(check(mid)) lo = mid+1;
           else hi = mid-1; 
        }

        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<hi;
        //
        cout<<"\n";
    }
}
