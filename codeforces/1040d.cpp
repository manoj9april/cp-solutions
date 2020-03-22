#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define scll(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())

#define dbg(name,x)  cerr << name << " is " << x << endl;

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second

#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double pi=acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt = 1e5 + 5;

ll n, m;
vi adj[502],lin,ck(lmt, true);
vpii e(lmt);
bool cyc = false,ok=false;
int vis[502];

bool dfs2(int p)
{
    vis[p] = 1;
    for (auto j : adj[p])
    {
        if (!ck[j])
            continue;
        if (!vis[e[j].s])
        {
            if (dfs2(e[j].s))
                return true;
        }
        else if (vis[e[j].s] == 1)
        {
            return true;
        }
    }
    vis[p] = 2;
    return false;
}
bool has_cycle()
{
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs2(i))
            return true;
    }
    return false;
}

void dfs1(int p)
{
    if (cyc || ok)
        return;
    vis[p] = 1;
    for (auto j : adj[p])
    {
        lin.pb(j);
        if (!vis[e[j].s])
        {
            dfs1(e[j].s);
        }
        else if (!cyc && vis[e[j].s] == 1)
        {

            int nod = e[j].s;
            for (int i = lin.size() - 1; i >= 0; i--)
            {
                ck[lin[i]] = false;
                if (!has_cycle())
                    ok = true;
                ;
                ck[lin[i]] = true;
                if (e[lin[i]].f == nod)
                {
                    break;
                }
            }
            cyc = true;
            return;
        }
        lin.ppb();
    }
    vis[p] = 2;
}

int main()
{
    fast
            cin >>
        n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].pb(i);
        e[i] = {u, v};
    }
    for (int i = 1; !cyc && i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    if (!cyc)
    {
        cout << "YES\n";
        return 0;
    }

    cout << (ok ? "YES" : "NO") << "\n";
}