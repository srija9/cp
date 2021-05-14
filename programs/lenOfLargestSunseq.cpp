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



int main(int argc, char const *argv[])
{
	init_code();
	
	int n;
	cin>>n;
	vector<ll> arr(n);
	loop(i,0,n-1) cin>>arr[i];
	vector<ll> dp(n,1);
	loop(i,0,n-1){
		loop(j,0,i-1){
			if(arr[i]>arr[j]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}
	ll ans = -inf;
	loop(i,0,n-1) ans=max(ans, dp[i]);
	cout<<ans;
	return 0;
}
