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

double dp[3005][3005]; // dp[i][j] -> prob to get atleast j heads with i coins

double coins(vector<double> &arr, int i, int x)
{
    if (x == 0)
        return 1;
    if (i == 0)
        return 0;

    if (dp[i][x] > -0.9)
        return dp[i][x];

    return dp[i][x] = arr[i] * coins(arr, i - 1, x - 1) + (1 - arr[i]) * coins(arr, i - 1, x);
}

int main(int argc, char const *argv[])
{
    init_code();

    int n;
    cin >> n;
    vector<double> arr(n + 1);
    memset(dp, -1, sizeof(dp));
    loop(i, 1, n) cin >> arr[i];
    cout << fixed << setprecision(10) << coins(arr, n, (n + 1) / 2);
    return 0;
}