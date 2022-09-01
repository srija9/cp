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
 
ll dp[22][(1<<22)];

ll matching(vector<vector<int> > &compat, int i, int mask, int n){
    if( i == n+1) {
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    ll ans = 0;
    loop(w, 0, n-1){
        bool available = (((1<<w)&(mask)) == 0) ? 0 : 1;
        if(available and compat[i][w+1] == 1){
            ans = ((ans%mod) + (matching(compat, i+1, mask^(1<<w), n))%mod)%mod;
        }
    }

    return dp[i][mask] = ans;
}

int main(int argc, char const *argv[])
{
init_code();
int n;
cin>>n;
vector<vector<int> > compat(n+1, vector<int>(n+1));
memset(dp, -1, sizeof(dp));
loop(i, 1, n) {
    loop(j, 1, n) {
        cin>>compat[i][j];
    }
}

cout<<matching(compat, 1, ((1<<n)-1), n);
 
return 0;
}