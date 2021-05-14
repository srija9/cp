#include<bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod			   1000000007
#define inf            1e18
#define endl 		   "\n"
#define mid(l,r)	   (l+(r-1)/2)
#define loop(i,a,b)	   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) for(int i=(a);i>=(b);i--)

void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

ll minCoinTD(int *coins, int n, int sum, int *dp){
	if(sum<0){
		return inf;
	}
	if(sum == 0) return 0;
	if(dp[sum] != -1) return dp[sum];
	ll result = inf;
	loop(i, 0, n-1){
		ll recursionResult = minCoinTD(coins, n, sum-coins[i], dp);
		if(recursionResult == inf){
			continue;
		}
		result = min(result, 1+recursionResult);
	}
	return dp[sum] = result;
}



int main(int argc, char const *argv[])
{
	init_code();
	
   ll n,x;
   cin>>n>>x;
   int *coins = new int[n];
   loop(i, 0 , n-1) cin>>coins[i];
   vector<ll> dp(x+1,inf);
   dp[0] = 0;
   loop(i, 1, x){
   	loop(j,0,x-1){
   		if(coins[j]>i) continue;
   		dp[i] = min(dp[i], 1+dp[i-coins[j]]);
   	}
   }
   if(dp[x] == inf) cout<<-1;
   else cout<<dp[x];
	return 0;
}
