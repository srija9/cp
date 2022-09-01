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
    // init_code();

    int n;
    cin >> n;

    //   vector<int> v;

    //     while(n>0) {
    //       v.push_back(n%2);
    //       n=n/2;
    //   }

    //   cout<<v.size()<<"\n";

    int A[n];

    for (int i = 0; i < (1 << n); i++)
    {
        cin >> A[i];
    }

    int dp[(1 << n) + 5][n + 5];

    for (int mask = 0; mask < (1 << n); mask++)
    {
        dp[mask][0] = A[mask];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (mask & (1 << (i - 1)))
            {
                dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << (i - 1))][i - 1];
            }
            else
            {
                dp[mask][i] = dp[mask][i - 1];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        cout << dp[mask][n] << " ";
    }

    return 0;
}