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

ll n;
cin>>n;

vector<ll> arr(n, 0);
loop(i, 0, n-1) cin>>arr[i];

vector<ll> dp(n, inf);
dp[0] = 0;
if(n==1) {
    cout<<dp[0];
    return 0;
}

dp[1] = abs(arr[0]-arr[1]);
loop(i, 2, n-1){
    dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
}

cout<<dp[n-1];
 
return 0;
}