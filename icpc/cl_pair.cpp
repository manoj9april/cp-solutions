#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define px second
#define py first

typedef pair<ll,ll> pll;

ll const lmt = 1e5+4;
ll const inf = 1e18+4;
pll pnts [lmt];

int compare(pll a, pll b)
{ 
        return a.px<b.px; 
}
ll sq(ll a){
    return (a*a);
}
double closest_pair(int n)
{
    sort(pnts,pnts+n,compare);
    double best=inf;
    set<pll> box;
    box.insert(pnts[0]);
    int left = 0;
    for (int i=1;i<n;++i)
    {
        while (left<i && pnts[i].px-pnts[left].px > best) box.erase(pnts[left++]);

        for(auto it=box.lower_bound({pnts[i].py-best, pnts[i].px-best}); 
            (it!=box.end()) && (it->py <= pnts[i].py+best); it++)
        {
            double new_d = sqrt( sq(pnts[i].py - it->py) + sq(pnts[i].px - it->px) ); 
            best = min(best, new_d);
        }
        box.insert(pnts[i]);
    }
    return best;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>pnts[i].first>>pnts[i].second;
    }
    
    ll ans = closest_pair(n);
    
    cout<<ans<<"\n";
    
}



