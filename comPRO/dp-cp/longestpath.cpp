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

vector<int> graph[100005];
int dp[100005];

int findLongestPath(int src)
{
    if (dp[src] != -1)
        return dp[src];

    int result = INT_MIN;
    bool no_neighbour = true;
    for (int neighbour : graph[src])
    {
        no_neighbour = false;
        result = max(result, findLongestPath(neighbour));
    }
    return dp[src] = no_neighbour ? 0 : result + 1;
}

int main(int argc, char const *argv[])
{
    init_code();

    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int result = INT_MIN;
    loop(i, 1, n)
    {
        result = max(result, findLongestPath(i));
    }

    cout << result;

    return 0;
}