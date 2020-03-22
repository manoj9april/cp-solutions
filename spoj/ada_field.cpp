#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        set<int> x,y;  multiset<int> xd,yd;
        x.insert(0); x.insert(n);
        y.insert(0); y.insert(m);
        xd.insert(n);
        yd.insert(m);
        int ty,pt; long long area=0;
        while(q--){
            cin>>ty>>pt;
            if(ty==0){
                x.insert(pt);
                auto it = x.upper_bound(pt);
                int hi = *it; it--;it--;
                int lo = *it;
                xd.erase(xd.find(hi-lo));
                xd.insert(pt-lo);
                xd.insert(hi-pt);
            }else{

                y.insert(pt);
                auto it = y.upper_bound(pt);
                int hi = *it; it--;it--;
                int lo = *it;
                yd.erase(yd.find(hi-lo));
                yd.insert(pt-lo);
                yd.insert(hi-pt);
            }

            area = 1LL*(*xd.rbegin())*(*yd.rbegin());
            cout<<area<<"\n";
        }
    }
}