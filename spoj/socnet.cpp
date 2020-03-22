#include <bits/stdc++.h>

using namespace std;

int const lmt = 2 * 1e4 + 1;
int const M = 1e9 + 7;

int root[lmt];
int size[lmt];
int fc[lmt];
long long cnt[lmt];

int find(int i)
{
    if (root[i] != i)
    {
        return root[i] = find(root[i]);
    }

    return i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // ini
        for (int i = 1; i <= n; i++)
        {
            size[i] = 1;
            root[i] = i;
            cnt[i] = 0;
        }
        //cin>>m;
        int a, b, ctr = 1;
        char ty;
        cin>>ty;
        while (ty!='O')
        {
            if (ty == 'I')
            {
                cin >> a >> b;

                int x = find(a);
                int y = find(b);
                if (x != y)
                {
                    if (size[x] > size[y])
                    {
                        size[x] += size[y];
                        cnt[x] += 1LL*((abs(a - b)) % 1000);
                        size[y] = 0;
                        root[y] = x;
                    }
                    else
                    {
                        size[y] += size[x];
                        size[x] = 0;
                        cnt[y] += 1LL*((abs(a - b)) % 1000);
                        root[x] = y;
                    }
                }
            }else{
                cin>>a;
                cout<<cnt[find(a)]<<"\n";
            }

            cin>>ty;
        }
    }

    return 0;
}