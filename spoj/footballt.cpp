#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    int n;
    cin >> n;
    while (n)
    {
        int neg[n] = {0};
        int pos[n] = {0};
        int ele;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ele;
                neg[i] += ele;
                pos[j] += ele;
            }
        }
        int before = 0, after = 0;
        for (int i = 0; i < n; i++)
        {
            before += pos[i];
            if (pos[i] - neg[i] > 0)
            {
                after += (pos[i] - neg[i]);
            }
        }

        cout<<t<<". "<<before<<" "<<after<<"\n";
        t++;
        cin>>n;
    }
    //int arr[n][n];
}