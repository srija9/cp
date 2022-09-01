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
 
int main(int argc, char const *argv[])
{
init_code();

ll n,k;
cin>>n>>k;

vector<ll> arr(n, 0);
loop(i, 0, n-1) cin>>arr[i];
vector<ll> dp(n, inf);
dp[0] = 0;
loop(i, 1, n-1){
    loop(j, 1, k){
        if(i-j < 0) break;
        dp[i] = min(dp[i], dp[i-j]+abs(arr[i]-arr[i-j]));
    }
}

cout<<dp[n-1];
 
return 0;
}