#include<iostream>
using namespace std;

int n;
int cost[20005];
int par[20005];

int cst(int i)
{
    int ans=0;
    while(par[i]!=i)
	{
	    ans+=cost[i];
	    i=par[i];
	}
	return ans;
}
int parent(int i)
{
	while(par[i]!=i)
	{
		cost[i]+=cost[par[i]];
		par[i]=par[par[i]];
		i=par[i];
	}
	return par[i];
}

void unite(int x,int y)
{
	int p1=parent(x);
	int p2=parent(y);
	if(p1==p2)
	{
	    return;
	}
	cost[x]=cst(y)+abs(x-y)%1000;
	par[p1]=p2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
    	for(int i=1 ; i<=n ; i++)
    	{
    		cost[i]=0;
    		par[i]=i;
    	}
    	//cout<<parent(3)<<endl;
    	
    	char ch;
    	cin>>ch;
    	while(ch!='O')
    	{
    		int x,y;
    		
    		if(ch=='I')
    		{
    			cin>>x>>y;
    			unite(x,y);
    		}
    		else
    		{
    		    cin>>x;
    		    cout<<cst(x)<<endl;
    		}
    		cin>>ch;
    	}   
    }
	return 0;
}