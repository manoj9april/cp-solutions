#include<bits/stdc++.h>

using namespace std;

struct acc{
    int val[6];
};

int const lmt = 1e5+5;

acc arr[lmt];

bool comp(acc &f, acc &s){
    
    for(int i=0; i<6; i++){
        if(f.val[i] == s.val[i]) continue;

        return f.val[i] < s.val[i];
    }
    
    return true;
}

bool isequal(acc f, acc s){
    for(int i=0; i<6; i++){
        if(f.val[i] != s.val[i]) return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cout << setfill('0');
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        //acc arr[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<6; j++){
                cin>>arr[i].val[j];
            }
        }

        sort(arr,arr+n,comp);
        int w[6] = {2,8,4,4,4,4};

        //cout<<endl;
        for(int i=0; i<n; i++){
            int j=i+1;
            int cnt=1;
            while(j<n && isequal(arr[i],arr[j])){
                i++;
                j++;
                cnt++;
            }
            for(int j=0; j<6; j++){
                cout<<setw(w[j]);
                cout<<arr[i].val[j]<<" ";
            }
            cout<<cnt<<"\n";
        }
        cout<<"\n";
    }
}