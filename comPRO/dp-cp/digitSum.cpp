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

ll dp[100005][105][2];

ll digit(string &k, int D, int pos, int d, bool c){
    if(dp[pos][d][c] != -1) return dp[pos][d][c];
    int ub = (c) ? (k[pos]-'0') : 9;
    if(pos == k.size() - 1){
        ll ans = 0;
        loop(x, 0, ub){
            if(x%D == d) ans++;
        }
        return ans;
    }

    ll ans = 0;
    loop(x, 0, ub){
        ans = (ans + digit(k, D, pos+1, (D+d-x%D)%D, c&&(x==ub)))%mod;
    }

    return dp[pos][d][c] = ans;
}

 
int main(int argc, char const *argv[])
{
    init_code();

    int D;
    string k;
    cin>>k;
    cin>>D;
    memset(dp, -1, sizeof(dp));
    cout<<(mod + digit(k, D, 0, 0, 1) - 1)%mod;
    
    return 0;
}