#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;

    int w=0,b=0;

    //bwbwbw...
    int pos[n/2];
    for(int i=0; i<n/2; i++){
        cin>>pos[i];
    }
    sort(pos,pos+n/2);
    int bp=1,wp=2;

    for(int i=0; i<n/2; i++){
        w += abs(pos[i]-wp);
        b += abs(pos[i]-bp);

        wp+=2;
        bp+=2;
    }

    cout<<min(w,b)<<"\n";
}