#include<bits/stdc++.h>
using namespace std;
vector<int> D(1000001);
vector<int> S(1000001,1);
int Find(int a)
{
    if(D[a]!=a)
        return D[a]=Find(D[a]);
    return a;
}
int main()
{
    int N,K;
    cin>>N>>K;
    for(int i=0;i<1000001;i++)
        D[i]=i;
    vector<pair<int,int>> V(K);
    map<int ,int> M;
    int n=0;
    int j=1;
    for(int i=0;i<K;i++)
    {
 
 
        int a,b;
        cin>>a>>b;
        if(M.find(a)==M.end())
        {
            M[a]=j;
            j++;
            n++;
        }
        if(M.find(b)==M.end())
        {
            M[b]=j;
            j++;
            n++;
        }
        V[i]={M[a],M[b]};
} //cout<<endl;
        for(int i=0;i<K;i++)
        {
            //cout<<V[i].first<<" "<<V[i].second<<endl;
            int x=Find(V[i].first);
            int y=Find(V[i].second);
            //cout<<endl<<x<<" "<<y<<endl;
            if(x!=y)
            {
                if(S[x] > S[y])
                {
                    S[x]+=S[y];
                    D[y]=x;
                }
                else
                {
                    S[y]+=S[x];
                    D[x]=y;
                }
            }
        }
        vector<int> T(n+1,0);
        for(int i=1;i<=n;i++)
            int x=Find(i);
        for(int i=1;i<=n;i++)
        {
 
            //cout<<D[i]<<" ";
            T[D[i]]=1;
        }
        int a=0;
        for(int i=0;i<n+1;i++)
            a+=T[i];
        //cout<<a<<endl;
        cout<<N-n+a<<endl;
    }
 
 