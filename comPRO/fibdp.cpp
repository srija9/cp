#include <bits/stdc++.h>
using namespace std;
 
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll             long long int
#define mod             1000000007
#define inf            1e18
#define endl           "\n"
#define mid(l,r)       (l+(r-l)/2)
#define loop(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
 
void init_code(){
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

int fibTD(int n, vector<int> &dp) {
	if(n == 0 or n == 1) return n;
	if(dp[n] != -1){
		// already computed
		return dp[n];
	}
	dp[n] = fib(n-1) + fib(n-2);
	return dp[n];
}

int fibBU(int n){
	if(n == 0 or n ==1) return n;
	vector<ll> dp(n+1, -1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
    init_code();
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);

    cout<<fibTD(n, dp)<<"\n";

    return 0;
}