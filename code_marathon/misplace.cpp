#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t=1;

    while(t--){

        ll a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            if(b==c){
                cout<<b<<" "<<0<<"\n";
                return 0;
            }
        }else if(b==0){
            if(a==c){
                cout<<a<<" "<<0<<"\n";
                return 0;
            }
        }else if(c==0){
            if(b==a){
                cout<<b<<" "<<0<<"\n";
                return 0;
            }
        }
        ll sum = a+b+c;
        ll minus = min(a,min(b,c));
        ll plus = max(a,max(b,c));
        ll mul = sum-minus-plus;
        bool got =false;

        if((minus+plus)%2 == 0){
            a = (minus+plus)/2;
            if(mul%a==0){
                b=mul/a;
                if(a+b==plus){
                    cout<<a<<" "<<b<<"\n";
                    return 0;
                }
            }
        }

        if((minus+mul)%2 == 0){
            a = (minus+mul)/2;
            if(plus%a==0){
                b=plus/a;
                if(a+b==mul){
                    cout<<a<<" "<<b<<"\n";
                    return 0;
                }
            }
        }

        cout<<-1<<"\n";
    }
}