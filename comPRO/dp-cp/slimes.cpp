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

ll dp[405][405];
ll sum[405][405];

ll slimes(vector<ll> &a, int i, int j){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll mincost = inf;
    loop(k, i, j-1) {
        mincost = min({ mincost, slimes(a, i, k) + slimes(a, k+1, j) + sum[i][j]});
    }

    return dp[i][j] = mincost;
}

int main(int argc, char const *argv[])
{
init_code();

ll n;
cin>>n;
vector<ll> a(n+1, 0);
loop(i, 1, n) cin>>a[i];

memset(dp, -1, sizeof(dp));
memset(sum, 0, sizeof(sum));

loop(i, 1,  n) {
    loop(j, i, n) {
        sum[i][j] = a[j] + (i == j) ? 0 : sum[i][j-1];
    }
}

cout<<slimes(a, 1, n);
 
return 0;
}