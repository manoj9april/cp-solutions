#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;
using namespace std::chrono; 

int const lmt=15;
ll a[lmt][5],b[lmt][5];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    
    auto start = high_resolution_clock::now();

    int T; cin>>T;
    for(int t=1; t<=T; t++){
        ll ans;
        
        cout<<"#"<<t<<" ";
        cout<<ans<<"\n";
    }

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time: "
         << duration.count()/1000/1000.0 << " seconds" << endl; 
    
}
