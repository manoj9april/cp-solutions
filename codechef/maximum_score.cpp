#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;

        vector<int>  arr[n];

        int ele;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>ele;
                arr[i].push_back(ele);
            }
        }

        for(int i=0; i<n; i++){
            sort(arr[i].begin(), arr[i].end());
        }

        int p,q;
        p=q=n-1;

        long long sum =0;
        bool notf=false;
        for(int i=n-2; i>=0; i--){
            if(arr[i][q]<arr[i+1][p]){
                sum += (long long)arr[i][q];
                continue;
            }  

            while(arr[i][q]>=arr[i+1][p]){
                q--;
                if(q<0){
                    notf = true;
                    break;
                }
            }
            if(notf) break;
            p=q;
            q=n-1;
        }

        if(notf){
            cout<<"-1\n";
        }else{
            cout<<sum<<endl;
        }

    }
}