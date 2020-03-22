#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+5;

int size[lmt],first[lmt],sec[lmt],third[lmt],root[lmt];

int find(int i){
    if(root[i]!=i){
        return root[i]=find(root[i]);
    }

    return root[i];
}

bool con[lmt];

int main(){
    int n,m,mn,mx,f,s,t;
    cin>>n>>m>>mn>>mx>>f>>s>>t;
    for(int i=1; i<=n; i++){
        size[i]=1;
        root[i]=i;
    }

    map<string,int> mp;

    string str,s1,s2,sr[n+1];
    int g,a,b,x,y;
    for(int i=1; i<=n; i++){
        cin>>str;
        cin>>g;
        mp[str]=i;
        sr[i]=str;
        if(g==1)first[i]++;
        else if(g==2)sec[i]++;
        else third[i]++;
    }

    for(int i=0; i<m; i++){
        cin>>s1>>s2;
        a = mp[s1];
        b = mp[s2];
        x = find(a);
        y = find(b);

        if(x!=y){
            if(size[x]+size[y]>mx) continue;
            if(first[x]+first[y]>f) continue;
            if(sec[x]+sec[y]>s) continue;
            if(third[x]+third[y]>t) continue;

            if(size[x]>size[y]){
                size[x] += size[y];
                first[x] += first[y];
                sec[x] += sec[y];
                third[x] += third[y];

                root[y]=x;
            }else{
                swap(x,y);
                size[x] += size[y];
                first[x] += first[y];
                sec[x] += sec[y];
                third[x] += third[y];

                root[y]=x;
            }
        }
    }

    int maxx=0;
    for(int i=1; i<=n; i++){
        if(size[i]>=mn && size[i]<=mx){
            if(size[i]>maxx){
                maxx =size[i];
            }
        }
    }
    if(maxx==0){
        cout<<"no groups\n";
        return 0;
    }
    vector<string> v;
    
    memset(con,false,sizeof con);

    for(int i=1; i<=n; i++){
        if(size[i]==maxx){
            con[i]=true;
        }
    }

    for(int i=1; i<=n; i++){
        if(con[find(i)]){
            v.push_back(sr[i]);
        }
    }

    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
}