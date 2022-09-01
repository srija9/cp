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
#define vv              vector<vector<ll> >
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

vector<ll> dp((1<<16), inf);
vector<ll> sums((1<<16),0);

ll calculateScore(vv &compat, int mask){
    ll ans = 0;
    loop(i, 0, 16){
        loop(j, i+1, 16){
            if(((mask & (1<<i)) != 0) and ((mask & (1<<j)) != 0)){
                ans += compat[i][j];
            }
        }
    }
    return ans;
}

void precomputeSums(vv &compat, int n){
    loop(subset, 1, (1<<n)-1) {//visiting all subsets
        sums[subset] = calculateScore(compat, subset);
    }
}

ll grouping(vv &compat, int mask){
    if(mask == 0) return 0;
    if(dp[mask] != inf) return dp[mask];
    ll ans = 0;
    for(int submask = mask; submask != 0; submask = (submask-1)&mask){
        ans = max(ans, sums[submask]+grouping(compat, mask ^ submask));
    }
    return dp[mask] = ans;
}
 
int main(int argc, char const *argv[])
{
    init_code();

    int n;
    cin>>n;
    vv arr(n, vector<ll> (n));
    loop(i, 0, n-1){
        loop(j, 0, n-1) {
            cin>>arr[i][j];
        }
    }

    precomputeSums(arr, n);
    cout<<grouping(arr, (1<<n)-1);
    
    return 0;
}