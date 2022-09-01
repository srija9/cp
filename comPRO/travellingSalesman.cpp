// DP + Bitmasking
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-1)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

ll dp[(1<<20) + 2][20];

int grid[4][4] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

ll tsp(int mask, int curr, int n){ 
    if(mask == ((1<<n)-1)){
        return grid[curr][0];
    }
    if(dp[mask][curr] != -1) return dp[mask][curr];
    ll ans = inf;

    for(int city = 0; city < n; city++){
        if((mask & (1<<city)) == 0) {
            ans = std::min(ans, tsp(mask|(1<<city), city, n) + grid[curr][city]);
        }
    }
    return dp[mask][curr] = ans;
}
 
int main(int argc, char const *argv[])
{
init_code();

memset(dp, -1, sizeof(dp));
cout<<tsp(1, 0, 4);
 
return 0;
}