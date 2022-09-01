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
#define vvi             vector<vector<ll> >
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

vvi multiply(vvi &a, vvi &b){
    int n = a.size();
    vvi res(n, vector<ll>(n, 0));
    loop(i, 0, n-1){
        loop(j, 0, n-1){
            loop(k, 0, n-1){
                res[i][j] = (res[i][j] + a[i][k]*a[k][j])%mod;
            }
        }
    }
    return res;
}

vvi power_(vvi &mat, ll exp){
    if(exp == 1) return mat;
    vvi res = power_(mat, exp/2);
    vvi ans = multiply(res, res);
    if(exp % 2 != 0) {
        return multiply(ans, mat);
    } else{
        return ans;
    }
}

ll walk(vvi &adj, ll k){
    int n = adj.size();
    vvi res = power_(adj, k);
    ll ans = 0;
    loop(i, 0, n-1){
        loop(j, 0, n-1){
            ans = (ans%mod + res[i][j]%mod)%mod;
        }
    }
    return ans;
}
 
int main(int argc, char const *argv[])
{
    init_code();

    ll n,k;
    cin>>n>>k;
    vvi adj(n, vector<ll>(n));
    loop(i, 0, n-1){
        loop(j, 0, n-1){
            cin>>adj[i][j];
        }
    }
    cout<<walk(adj, k);
    
    return 0;
}