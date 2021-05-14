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
	ll n,k;
	cin>>n>>k;
	vector<ll> arr(n);
	loop(i,0,n-1) cin>>arr[i];

	vector<ll> dp(k+1,0);
	loop(i,1,k){
		for(int val:arr){
			if(val>i) continue;
			if(dp[i-val]==0) dp[i]=1;
		}
	}
     
     cout<<(dp[k]==1? "First":"Second");

	return 0;
}
