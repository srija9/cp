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

vector<ll> tree[100005];
ll dp[100005][2];

ll independentSet(int node, int parent, int c){
    if(dp[node][c] != -1) return dp[node][c];
    ll ans = 0;
    ll w0 = 1;
    for(auto child:tree[node]){
        if(child != parent){
            w0 = ((w0%mod)*(independentSet(child, node, 0))%mod)%mod;
        }        
    }
    ans = ((ans%mod) + (w0%mod))%mod;
    if(not c){
        ll w1 = 1;
        for(auto child:tree[node]){
            if(child != parent){
                w1 = ((w1%mod)*(independentSet(child, node, 1))%mod)%mod;
            }        
        }
        ans = ((ans%mod) + (w1%mod))%mod;
    }
    return dp[node][c] = ans;
}

int main(int argc, char const *argv[])
{
    init_code();
    ll n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    ll x,y;
    loop(i, 0, n-2){
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);  
    }

    cout<<independentSet(1, -1, 0);

    return 0;
}