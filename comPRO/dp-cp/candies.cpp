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
 
ll dp[105][10005];
 ll candies(vector<ll> &arr, ll n, ll k){
     loop(j, 0, k){
         dp[1][j] = (j > arr[1]) ? 0 : 1;
     }
     loop(i, 2, n){
         loop(j, 0, k){
             if(j == 0){
                 dp[i][j] = dp[i-1][j];
             }
             else{
                 dp[i][j] = (mod + dp[i][j-1]%mod + dp[i-1][j]%mod - ((j-arr[i]-1 >= 0) ? dp[i-1][j-arr[i]-1]%mod : 0))%mod;
             }
         }
     }
     return dp[n][k];
 }

int main(int argc, char const *argv[])
{
init_code();
ll n, k;
cin>>n>>k;
memset(dp, -1, sizeof(dp));
vector<ll> arr(n+1, 0);
loop(i,1,n){
    cin>>arr[i];
}
cout<<candies(arr, n, k);
 
return 0;
}