#include<bits/stdc++.h>

#define eps 1e-7

using namespace std;


int const lmt = 1e4+2;
struct tank{
    int b,v,h;
};
int n; 
tank tk[lmt];

int volume(long double h){
    int vol=0;
    for(int i=0; i<n; i++){
        if(tk[i].b<h){
            if(tk[i].b + tk[i].h<h)
                vol += tk[i].v;
            else{
                vol += (h-tk[i].b)*1.0/tk[i].h*tk[i].v;
            }
        }
    }
    return vol;
}

int main(){
    int t; cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        
        cin>>n;
        int tv=0;
        int b,h,w,d;
        int mxh=0;
        for(int i=0; i<n; i++){
            cin>>b>>h>>w>>d;
            mxh = (mxh,b+h);
            tk[i].b=b;
            tk[i].h=h;
            tk[i].v=(h*w*d);
            tv += tk[i].v;
        }
        int vol; cin>>vol;
        if(vol>tv){
            cout<<"OVERFLOW\n";
            continue;
        }

        long double lo = 0,hi=mxh;
        long double mid;
        int itr=100;
        while(itr--){
            mid = (lo+hi)/2;
            int vv = volume(mid);
            //if(abs(vv-vol)<= eps) break;
            if(vv < vol) lo =mid;
            else hi=mid;
        }

        cout<<mid<<"\n";
    }
}