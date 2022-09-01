#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define mid(l, r) (l + (r - 1) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[])
{
    init_code();

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            if ((s1[i - 1] == s2[j - 1]))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m];

    int ans = dp[n][m];
    string str(ans, ' ');
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str[ans - 1] = s1[i - 1];
            i--;
            j--;
            ans--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return 0;
}