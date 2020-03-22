#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 1001;
ll prevv[26],nextt[26],pre[26];
void cl(){
    for(ll i=0; i<26; i++){
        prevv[i]=pre[i]=nextt[i]=0;
    }
}

int main(){
    ll t; cin>>t;
    string s;
    while(t--){
        cl();
        cin>>s;
        ll n = s.length();
        ll inv[n],ttl=0;
        
        for(ll i=0; i<n; i++){
            nextt[s[i]-'a']++;
            inv[i]=0;
            for(ll j=0; j<(s[i]-'a'); j++){
                inv[i] += nextt[j];
            }
        }
        ll last=nextt[25];
        cl();
        for(ll i=n-1; i>=0; i--){
            nextt[s[i]-'a']++;
            for(ll j=(s[i]-'a'+1); j<=25; j++){
                inv[i] += nextt[j];
            }
        }
        for(ll i=0; i<n; i++)ttl += inv[i];

        ll cost,ans=1e16;
        for(ll i=0; i<n; i++){
            nextt[s[i]-'a']--;
            ll sum=0,ps=0;
            for(ll j=0; j<26; j++)ps+=nextt[j];
            for(ll j=0; j<26; j++){
                ps -= nextt[j];
                cost =(ttl+2*(sum+ps-inv[i]))/2+abs(int(s[i]-'a')-j);
                ans = min(ans,cost);
                sum += prevv[j];
            }
            prevv[s[i]-'a']++;
        }
        cout<<ans<<"\n";
    }
}

