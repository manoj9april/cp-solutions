#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (i == 0)
            {
                if (n == 1 || s[i + 1] == '0')
                {
                    ok = false;
                    break;
                }
            }
            else if (i == n - 1)
            {
                if (s[i - 1] == '0')
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (s[i - 1] == '0' && s[i + 1] == '0')
                {
                    ok = false;
                    break;
                }
            }
        }
        else
        {
            if (i > 0)
            {
                if (s[i - 1] == '1')
                {
                    ok = false;
                    break;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}
