#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

int main(){
    int t; cin>>t;
    while(t--){
        string str;
        cin>>str;
        int f[26]={0},s[26]={0};
        int len = str.length();

        for(int i=0,j=len-1; i<j; i++,j--){
            f[str[i]-'a']++;
            s[str[j]-'a']++;
        }
        bool ans = true;
        for(int i=0; i<26; i++){
            if(f[i]!=s[i]){
                ans = false;
                break;
            }
        }

        cout<<(ans?"YES\n":"NO\n");
    }
}